/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_remove_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:14:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/10/11 12:32:07 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdll.h"

// TODO: the head and tail of the cdll are not being set to null

void	cdll_remove_node(t_cdll *list, struct s_cdll_node *node, void (*del)(void *))
{
	if (!list || !node || list->count == 0)
		return ;
	if (list->count == 1)
	{
		list->head = 0;
		list->tail = 0;
	}
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		if (node == list->head)
			list->head = node->next;
		else if (node == list->tail)
			list->tail = node->prev;
	}
	node->next = 0;
	node->prev = 0;
	if (del)
		del(node->data);
	free(node);
	list->count--;
}
