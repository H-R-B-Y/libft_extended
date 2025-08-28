/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cdll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:02:16 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/26 12:27:03 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdll.h"

struct s_cdll_node	*init_node(void *data)
{
	struct s_cdll_node	*node;

	node = ft_calloc(1, sizeof(struct s_cdll_node));
	if (!node)
		return ((void *)0);
	node->data = data;
	return (node);
}

void	delete_node(struct s_cdll_node **node, void (*del)(void *))
{
	if (!node || !*node)
		return ;
	if ((*node)->data && del)
		del((*node)->data);
	free(*node);
	*node = 0;
}

t_cdll	*init_cdll(void)
{
	t_cdll	*list;

	list = ft_calloc(1, sizeof(t_cdll));
	if (!list)
		return ((void *)0);
	return (list);
}

void	delete_cdll(t_cdll **list, void (*del)(void *))
{
	struct s_cdll_node	*tmp;
	struct s_cdll_node	*node;

	if (!list || !*list)
		return ;
	tmp = (*list)->head;
	while (tmp && tmp != (*list)->tail)
	{
		node = tmp->next;
		delete_node(&tmp, del);
		tmp = node;
	}
	delete_node(&tmp, del);
	free(*list);
	*list = 0;
	return ;
}
