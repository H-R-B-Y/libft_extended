/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:59:05 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/04 14:32:51 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc_a.h"

static size_t	round_to_block_size(size_t size)
{
	if (size % ALLOC_A_DEFAULT_BLOCK_SIZE == 0)
		return (size);
	return ((size / ALLOC_A_DEFAULT_BLOCK_SIZE + 1) * ALLOC_A_DEFAULT_BLOCK_SIZE);
}

int	_allocate_more(
	size_t size,
	struct s_alloc_a_node **addr,
	t_alloc_a_callback callback,
	void *context
)
{
	char					allocated_block[ALLOC_A_DEFAULT_BLOCK_SIZE
		+ sizeof(struct s_alloc_a_node)];
	struct s_alloc_a_node	*new_node;

	new_node = (struct s_alloc_a_node *)&allocated_block[0];
	*addr = new_node;
	new_node->size = ALLOC_A_DEFAULT_BLOCK_SIZE;
	new_node->next = NULL;
	if (size - ALLOC_A_DEFAULT_BLOCK_SIZE > 0)
	{
		return (_allocate_more(size - ALLOC_A_DEFAULT_BLOCK_SIZE,
				&new_node->next, callback, context));
	}
	return (callback(context));
}

int	ft_alloc_a_create(
	size_t size,
	struct s_alloc_a **out_alloc_a,
	t_alloc_a_callback callback,
	void *context
)
{
	char				allocated_block[ALLOC_A_DEFAULT_BLOCK_SIZE
		+ sizeof(struct s_alloc_a_node)];
	struct s_alloc_a	alloc_a;
	int					res;
	size_t				rounded_size;
	size_t				recursion_depth;

	if (!out_alloc_a || size == 0 || !callback)
		return (-1);
	rounded_size = round_to_block_size(size);
	if (rounded_size > ALLOC_A_MAX_STACK_USAGE)
		return (-1);
	recursion_depth = rounded_size / ALLOC_A_DEFAULT_BLOCK_SIZE;
	if (recursion_depth > ALLOC_A_MAX_RECURSION_DEPTH / 2)
		return (-1);
	alloc_a.free_list = (struct s_alloc_a_node *)&allocated_block[0];
	alloc_a.free_list->size = ALLOC_A_DEFAULT_BLOCK_SIZE;
	alloc_a.free_list->next = NULL;
	alloc_a.used_memory = 0;
	alloc_a.total_memory = rounded_size;
	*out_alloc_a = &alloc_a;
	if (rounded_size > ALLOC_A_DEFAULT_BLOCK_SIZE)
	{
		res = _allocate_more(rounded_size - ALLOC_A_DEFAULT_BLOCK_SIZE,
				&alloc_a.free_list->next, callback, context);
		(*out_alloc_a) = NULL;
		return (res);
	}
	res = callback(context);
	(*out_alloc_a) = NULL;
	return (res);
}
