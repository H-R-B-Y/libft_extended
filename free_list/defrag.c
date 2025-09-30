/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defrag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:57:08 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/30 13:09:00 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list_internal.h"

int	node_is_contiguous(t_free_list *list,
	t_free_list_node *left, t_free_list_node *right)
{
	t_u32 left_offset;
	t_u32 right_offset;
	t_u32 expected_right_offset;

	if (!list || !left || !right)
		return (0);
	if (left > right)
		return (0);
	left_offset = ptr_to_offset(list, left);
	right_offset = ptr_to_offset(list, right);
	expected_right_offset = left_offset + sizeof(t_free_list_node) + left->size;
	return (expected_right_offset == right_offset);
}

int	join_nodes(t_free_list *list,
	t_free_list_node *left, t_free_list_node *right)
{
	if (!list || !left || !right)
		return (0);
	left->next = right->next;
	left->size += right->size + sizeof(t_free_list_node);
	return (1);
}

/**
 * @brief Defragment the free list by coalescing adjacent free blocks.
 * 
 * @param list Pointer to the free list
 */
void			defragment_free_list(t_free_list *list)
{
	t_free_list_node	*current_node;
	t_free_list_node	*next;

	if (!list || list->head == FREE_LIST_NULL_OFFSET)
		return ;
	current_node = offset_to_ptr(list, list->head);
	while (current_node
		&& current_node->next != FREE_LIST_NULL_OFFSET)
	{
		next = next_node(list, current_node);
		if (!next)
			break ;
		if (node_is_contiguous(list, current_node, next)
			&& join_nodes(list, current_node, next))
			continue ;
		current_node = next;
	}
}
