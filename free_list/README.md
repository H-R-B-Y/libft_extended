# Free List Memory Management

## Overview

Custom memory allocator using a free list for efficient memory management, especially in scenarios requiring frequent allocations and deallocations.

### Features
 - Fixed arena size: Allocates a predefined memory block for managing allocations.
 - Embedded metadata: Each allocation includes metadata for size.
 - Automatic coalescing: Merges adjacent free blocks to minimize fragmentation.
 - First fit allocation strategy: Allocates the first suitable block found.
 - Relative offsets: Uses offsets instead of pointers for portability and safety, allowing the memory block to be moved / resized / serialized without invalidating pointers.

## Implementation Details

### Structures

There are two main structures used in this:
 - `t_free_list_node`: This is a metadata block that precedes each allocation. It contains:
   - `content`: A pointer to the start of the allocated memory. (Note: This is not a separate allocation; it points to the memory immediately after the node.)
   - `size`: Size of the allocated block.
   - `next`: Offset to the next node in the free list.

 - `t_free_list`: This structure manages the entire memory arena. It contains:
   - `arena`: Pointer to the start of the memory block.
   - `total_size`: Total size of the memory arena.
   - `used_size`: Total size currently allocated. (NOT IMPLEMENTED)
   - `head`: Offset to the first node in the free list.

The following MACRO is defined: 
 - `FREE_LIST_NULL_OFFSET` - Represents a null offset in the free list, indicating the end of the list.
 Because offsets are used instead of direct pointers, we cant use NULL as a sentinel value. So u32 MAX is used instead.

### Functions
 - `t_returncode	init_free_list(t_free_list *list, size_t total_size);`
  Initializes the free list with a specified total size.
 - `void			destroy_free_list(t_free_list *list);`
  Cleans up the free list and frees the allocated memory.
 - `void			*checkout_free_list(t_free_list *list, size_t size);`
  Allocates a block of memory of the specified size from the free list.
 - `t_returncode	return_free_list(t_free_list *list, void *ptr);`
  Returns a previously allocated block of memory back to the free list.
 - `void			defragment_free_list(t_free_list *list);`
  Coalesces adjacent free blocks to reduce fragmentation.
 - `t_u32			fragment_node(t_free_list *list, t_u32 node_offset, size_t size);`
  Splits a free block into an allocated block and a smaller free block if the requested size is smaller than the available block.
 - `t_returncode	resize_free_list(t_free_list *list, size_t new_size);`
  Resizes the memory arena of the free list.

### Memory Layout

When initialized the arena will contain a single large free block of size:
`total_size - sizeof(t_free_list_node)`

Each subsequent allocation will carve out a block from this free block, adding a `t_free_list_node` before the allocated memory to store metadata.

When a block is freed, it is added back to the free list and adjacent free blocks are coalesced to minimize fragmentation.

Example:
```
[Free List Node][Allocated Block][Free List Node][Free Block]...
```


## Notes

This implementation was designed for the a ray tracing project, while it may not be the best implementation due to the wasted space for metadata, it should be good enough for the purpose of the project.


## TODO

 - Currently each node has a pointer to its content, this is incredibly redundant as the content is always located contiguously after the node. This pointer can be removed to save space.
 - Implement `used_size` tracking in `t_free_list`.

### Fututre ideas to test out

- Remove the node data from the allocations to be more memory efficient, though we will need to find a way to track 'free's' that dont have enough space for the node metadata.
- Implement Max Heap for finding best fit allocations. (Max heap might not be the best approach)
- Abstract the relative offset logic for easier reuse in other projects.