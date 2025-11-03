
#ifndef FT_ALLOC_A_H
# define FT_ALLOC_A_H

# include "defined.h"
# include "ft_free_list.h"
# include "ft_mem.h"

# ifndef ALLOC_A_DEFAULT_BLOCK_SIZE
/// @brief Default block size for stack allocation (2KB)
#  define ALLOC_A_DEFAULT_BLOCK_SIZE 2048
# endif

# ifndef ALLOC_A_MAX_STACK_USAGE
/// @brief Maximum stack usage allowed for the allocator (4MB)
#  define ALLOC_A_MAX_STACK_USAGE (4 * 1024 * 1024)
# endif

# ifndef ALLOC_A_MAX_RECURSION_DEPTH
/// @brief Maximum recursion depth for allocations
#  define ALLOC_A_MAX_RECURSION_DEPTH 1000
# endif

/// @brief Callback type for allocation completion
typedef int	(*t_alloc_a_callback)(void *context);

struct s_alloc_a_node
{
	/// @brief Size of the free block
	size_t					size;
	/// @brief Pointer to the next free block
	struct s_alloc_a_node	*next;
};


struct s_alloc_a
{
	/// @brief Pointer to the head of the free list
	struct s_alloc_a_node	*free_list;
	/// @brief Amount of memory currently used
	size_t					used_memory;
	/// @brief Total memory managed by the allocator
	size_t					total_memory;
};

/**
 * @brief Create a new stack-based free list allocator
 * 
 * This creates a new free list allocator on the stack
 * this will not provide any persistent data to the callee function
 * the callback must make use of the allocator.
 * 
 * This will return -1 if:
 * - out_alloc_a is NULL
 * - size is 0
 * - callback is NULL
 * - size exceeds ALLOC_A_MAX_STACK_USAGE
 * - recursion depth exceeds ALLOC_A_MAX_RECURSION_DEPTH / 2
 * 
 * The size of the allocator will be rounded up to the nearest
 * multiple of ALLOC_A_DEFAULT_BLOCK_SIZE.
 * 
 * @param size Max size of the allocator
 * @param out_alloc_a where to store the created allocator
 * @param callback Callback function that will use the allocator
 * @param context Argument to pass to the callback
 * @return int -1 on failure, otherwise the return value of the callback
 */
int		ft_alloc_a_create(size_t size, struct s_alloc_a **out_alloc_a,
			t_alloc_a_callback callback,
			void *context);
	
/**
 * @brief Checkout a new block of memory from the allocator
 * 
 * This will find a suitable free block, split it if necessary,
 * then return a pointer to the allocated memory.
 * 
 * Note that a size cannot be greater than the
 * ALLOC_A_DEFAULT_BLOCK_SIZE - sizeof(struct s_alloc_a_node)
 * 
 * @param alloc_a The allocator
 * @param size Size of the block to checkout
 * @return void* Pointer to allocated memory or NULL on failure
 */
void	*ft_alloc_a_checkout(struct s_alloc_a *alloc_a, size_t size);

/**
 * @brief Return a previously checked out block to the allocator
 * 
 * @warning This MUST be a pointer previously obtained from ft_alloc_a_checkout
 * in the event that it is not, the behavior is undefined and will likely lead to
 * memory corruption.
 * 
 * This will merge the returned block with adjacent free blocks if possible.
 * 
 * Note that because of the nature of this allocator, you do not need to 
 * checkin all allocated blocks, only those you wish to reuse.
 * 
 * @param alloc_a 
 * @param ptr 
 * @return void* 
 */
void	*ft_alloc_a_checkin(struct s_alloc_a *alloc_a, void *ptr);

#endif
