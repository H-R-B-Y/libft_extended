/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:22:19 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 19:28:11 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list_internal.h"

void	*free_list_get_ptr(
						t_free_list *list,
						t_free_list_ptr offset)
{
	if (!list || !list->arena || offset == FREE_LIST_NULL_OFFSET)
		return (0);
	return ((char *)list->arena + offset);
}

t_free_list_ptr	free_list_get_offset(
									t_free_list *list,
									void *ptr)
{
	if (!list || !list->arena || !ptr)
		return (FREE_LIST_NULL_OFFSET);
	return ((char *)ptr - (char *)list->arena);
}

void	*offset_to_ptr(t_free_list *list, t_u32 offset)
{
	if (!list || offset == FREE_LIST_NULL_OFFSET || offset >= list->total_size)
		return (0);
	return ((void *)list->arena + offset);
}

t_u32	ptr_to_offset(t_free_list *list, void *ptr)
{
	if (!list)
		return (FREE_LIST_NULL_OFFSET);
	return ((void *)ptr - (void *)list->arena);
}
