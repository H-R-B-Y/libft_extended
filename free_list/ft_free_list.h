
#ifndef FT_FREE_LIST_H
# define FT_FREE_LIST_H

# include "defined.h"
# include "ft_mem.h"
# include <stdint.h>

// Sentinel value for "no next node" - using max value since it's impossible as a real offset
# define FREE_LIST_NULL_OFFSET UINT32_MAX

// pollution
typedef struct s_free_list_node	t_free_list_node;
typedef struct s_free_list		t_free_list;

struct s_free_list_node
{
	t_u32					content;
	size_t					size;
	t_u32					next; // use offsets in the arena
};

struct s_free_list
{
	void					*arena;
	size_t					total_size;
	size_t					used_size;
	t_u32					head; // use offsets in the arena
};

/**
 * @brief Initialize a free list with a given total size.
 * 
 * @param list Pointer to the list to initialize
 * @param total_size Total size of the memory arena
 * @return t_returncode 
 */
t_returncode	init_free_list(t_free_list *list, size_t total_size);

/**
 * @brief Free the memory arena inside the free list.
 * 
 * @param list Pointer to the list to destroy
 */
void			destroy_free_list(t_free_list *list);

/**
 * @brief Create a free list object (allocates memory for the struct).
 * 
 * @param total_size Total size of the memory arena
 * @return t_free_list* Pointer to the created free list
 */
t_free_list		*create_free_list(size_t total_size);

/**
 * @brief Free a free list object (frees the memory used by the struct).
 * 
 * @param list Pointer to the list to free
 */
void			free_free_list(t_free_list *list);

/**
 * @brief Allocate memory from the free list.
 * 
 * @param list Pointer to the list to allocate from 
 * @param size Size of the memory to allocate
 * @return void* Pointer to the allocated memory, or NULL if allocation failed
 */
void			*checkout_free_list(t_free_list *list, size_t size);

/**
 * @brief Return memory back to the free list.
 * 
 * @param list Pointer to the list to return to
 * @param ptr Pointer to the memory to return
 * @param size Size of the memory being returned
 * @return t_returncode RETURN_OK on success, RETURN_ERROR on failure
 */
t_returncode	return_free_list(t_free_list *list, void *ptr);


/**
 * @brief Defragment the free list by coalescing adjacent free blocks.
 * 
 * @param list Pointer to the free list
 */
void			defragment_free_list(t_free_list *list);

/**
 * @brief Fragment a free list node into smaller chunks.
 * 
 * @param list Pointer to the free list
 * @param node_offset Offset of node to fragment
 * @param size Size of the first fragment
 * @return t_u32 Offset of the right fragment
 */
t_u32			fragment_node(t_free_list *list, t_u32 node_offset, size_t size);

/**
 * @brief Resize the memory arena of a free list.
 * 
 * @param list Pointer to the free list
 * @param new_size New size of the memory arena
 * @return t_returncode RETURN_OK on success, RETURN_ERROR on failure
 * or RETURN_FATAL if memory allocation fails
 */
t_returncode resize_free_list(t_free_list *list, size_t new_size);

#endif
