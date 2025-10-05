/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cdll_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:17:20 by hbreeze           #+#    #+#             */
/*   Updated: 2025/10/05 12:17:33 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdll.h"

struct s_cdll_node	*cdll_init_node(void *data)
{
	struct s_cdll_node	*node;

	node = ft_calloc(1, sizeof(struct s_cdll_node));
	if (!node)
		return ((void *)0);
	node->data = data;
	return (node);
}

void	cdll_delete_node(struct s_cdll_node **node, void (*del)(void *))
{
	if (!node || !*node)
		return ;
	if ((*node)->data && del)
		del((*node)->data);
	free(*node);
	*node = 0;
}