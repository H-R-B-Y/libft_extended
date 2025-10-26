/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:52:49 by hbreeze           #+#    #+#             */
/*   Updated: 2025/10/26 15:37:19 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list_internal.h"


t_returncode init_free_list(t_free_list *free_list, size_t size)
{
	if (!free_list || size == 0)
		return (RETURN_ERROR);
	free_list->arena = ft_calloc(size, sizeof(char));
	if (!free_list->arena)
		return (RETURN_FATAL);
	free_list->head = 0;
	free_list->total_size = size;
	free_list->used_size = 0;
	((t_free_list_node *)free_list->arena)->content = 0 + sizeof(t_free_list_node);
	((t_free_list_node *)free_list->arena)->next = FREE_LIST_NULL_OFFSET;
	((t_free_list_node *)free_list->arena)->size = size - sizeof(t_free_list_node);
	return (RETURN_OK);
}

void	destroy_free_list(t_free_list *list)
{
	if (!list)
		return;
	if (list->arena)
		free(list->arena);
	list->arena = 0;
	list->total_size = 0;
	list->used_size = 0;
	list->head = 0;
	return ;
}
