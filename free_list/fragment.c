/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:25:24 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/30 13:09:58 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list_internal.h"

// node offset is the pointer to the list_node we are fragmenting
// size if the size of content after the fragment
t_u32	fragment_node(t_free_list *list, t_u32 node_offset, size_t size)
{
	t_free_list_node	*left_fragment;
	t_free_list_node	*right_fragment;
	t_u32				right_fragment_offset;

	if (!list || node_offset == list->total_size
		|| node_offset == FREE_LIST_NULL_OFFSET
		|| size == 0)
		return (FREE_LIST_NULL_OFFSET);
	left_fragment = (void *)(list->arena + node_offset);
	right_fragment_offset = node_offset
		+ sizeof(t_free_list_node) + size;
	right_fragment = (void *)(list->arena + right_fragment_offset);
	right_fragment->content = right_fragment_offset + sizeof(t_free_list_node);
	right_fragment->next = left_fragment->next;
	right_fragment->size = left_fragment->size
		- (sizeof(t_free_list_node) + size);
	// left_fragment->next = node_offset + size;
	left_fragment->size = size;
	return (right_fragment_offset);
}
