/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:24:21 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:08:09 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list_internal.h"

t_free_list_node	*next_node(t_free_list *list, t_free_list_node *node)
{
	if (!list || !node)
		return (0);
	if (node->next == FREE_LIST_NULL_OFFSET)
		return (0);
	return ((t_free_list_node *)((void *)list->arena + node->next));
}

t_free_list_node	*prev_node(t_free_list *list, t_free_list_node *node)
{
	t_u32				current_offset;
	t_u32				node_offset;
	t_free_list_node	*current;

	if (!list || !node)
		return (0);
	if (!ptr_is_part_of_freelist(list, node))
		return (0);
	node_offset = ptr_to_offset(list, node);
	if (node_offset == FREE_LIST_NULL_OFFSET
		|| list->head == node_offset)
		return (0);
	current_offset = list->head;
	while (current_offset < list->total_size
		&& current_offset != FREE_LIST_NULL_OFFSET)
	{
		current = (t_free_list_node *)((void *)list->arena + current_offset);
		if (current == node)
			return (0);
		if (current->next == node_offset)
			return (current);
		current_offset = current->next;
	}
	return (0);
}
