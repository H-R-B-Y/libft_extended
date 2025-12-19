/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:38:10 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:08:45 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list_internal.h"

int	ptr_is_part_of_freelist(t_free_list *list, void *ptr)
{
	if (!list || !ptr)
		return (0);
	return (ptr >= (void *)list->arena
		&& (char *)ptr - (char *)list->arena < (long int)list->total_size);
}

t_returncode	return_free_list(t_free_list *list, t_free_list_ptr ptr)
{
	t_u32				*prev_next;
	t_u32				returnable_offset;
	t_free_list_node	*node;
	t_free_list_node	*returnable;

	if (!list)
		return (RETURN_ERROR);
	returnable = (t_free_list_node *)
		((char *)free_list_get_ptr(list, ptr) - sizeof(t_free_list_node));
	if (!ptr_is_part_of_freelist(list, returnable))
		return (RETURN_ERROR);
	returnable_offset = ptr_to_offset(list, returnable);
	prev_next = &list->head;
	node = offset_to_ptr(list, list->head);
	while (node && ptr_to_offset(list, node) < returnable_offset)
	{
		prev_next = &node->next;
		node = next_node(list, node);
	}
	(*prev_next) = returnable_offset;
	returnable->next = FREE_LIST_NULL_OFFSET;
	if (node)
		returnable->next = ptr_to_offset(list, node);
	defragment_free_list(list);
	return (RETURN_OK);
}
