/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_free_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:47:39 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:08:16 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list_internal.h"

static void	update_free_list_after_resize(t_free_list *list, size_t old_size)
{
	t_free_list_node	*node;
	t_u32				*last_next;
	size_t				new_space;
	t_u32				new_node_offset;

	if (!list || old_size >= list->total_size)
		return ;
	new_space = list->total_size - old_size;
	node = offset_to_ptr(list, list->head);
	last_next = &list->head;
	while (node)
	{
		last_next = &node->next;
		node = next_node(list, node);
	}
	new_node_offset = old_size;
	*last_next = new_node_offset;
	node = offset_to_ptr(list, new_node_offset);
	node->content = new_node_offset + sizeof(t_free_list_node);
	node->next = FREE_LIST_NULL_OFFSET;
	node->size = new_space - sizeof(t_free_list_node);
	defragment_free_list(list);
}

t_returncode	resize_free_list(t_free_list *list, size_t new_size)
{
	void	*new_arena;
	size_t	copy_size;

	if (!list || new_size == 0 || new_size <= list->total_size)
		return (RETURN_ERROR);
	new_arena = ft_calloc(new_size, sizeof(char));
	if (!new_arena)
		return (RETURN_FATAL);
	copy_size = list->total_size;
	if (new_size < list->used_size)
		copy_size = new_size;
	ft_memcpy(new_arena, list->arena, copy_size);
	free(list->arena);
	list->arena = new_arena;
	list->total_size = new_size;
	update_free_list_after_resize(list, copy_size);
	return (RETURN_OK);
}
