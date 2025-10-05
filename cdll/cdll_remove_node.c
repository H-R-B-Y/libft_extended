/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_remove_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:14:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/10/05 19:15:09 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdll.h"

void	cdll_remove_node(t_cdll *list, struct s_cdll_node *node, void (*del)(void *))
{
	if (!list || !node || list->count == 0)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	else
		list->head = node->next;
	if (node->next)
		node->next->prev = node->prev;
	else
		list->tail = node->prev;
	if (del)
		del(node->data);
	free(node);
	list->count--;
}
