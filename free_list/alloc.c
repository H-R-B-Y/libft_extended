/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:57:13 by hbreeze           #+#    #+#             */
/*   Updated: 2025/10/26 15:41:10 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "free_list_internal.h"

static void	*checkout(
	t_free_list *list,
	size_t size,
	t_free_list_node *node,
	t_u32 *last_next
)
{
	if (node->size >= size + sizeof(t_free_list_node) + 1)
		(*last_next) = fragment_node(list,
			(void *)node - (void *)list->arena, size);
	else
		(*last_next) = node->next;
	return ((void *)(list->arena + node->content));
}
// TODO: update usage statistics
t_free_list_ptr	checkout_free_list(t_free_list *list, size_t size)
{
	t_free_list_node	*node;
	t_u32				*last_next;
	t_u32				node_offset;

	if (!list || size == 0 || list->head == list->total_size
		|| list->head == FREE_LIST_NULL_OFFSET)
		return (0);
	node_offset = list->head;
	last_next = &list->head;
	while (node_offset != FREE_LIST_NULL_OFFSET
		&& node_offset < list->total_size)
	{
		node = (t_free_list_node *)((void *)list->arena + node_offset);
		if (node->size >= size)
			return (free_list_get_offset(list,
					checkout(list, size, node, last_next)));
		last_next = &node->next;
		node_offset = node->next;
	}
	return (0); // didnt find a valid space 
}

