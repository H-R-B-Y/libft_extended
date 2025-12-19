/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cdll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:02:16 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 20:04:39 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdll.h"

t_cdll	cdll_init(void)
{
	return (
		(t_cdll){
		0
	});
}

void	cdll_destroy(t_cdll *list, void (*del)(void *))
{
	struct s_cdll_node	*tmp;
	struct s_cdll_node	*node;

	if (!list)
		return ;
	tmp = (list)->head;
	while (tmp && tmp != (list)->tail)
	{
		node = tmp->next;
		cdll_delete_node(&tmp, del);
		tmp = node;
	}
	cdll_delete_node(&tmp, del);
	return ;
}

void	cdll_free(t_cdll *list, void (*del)(void *))
{
	if (!list)
		return ;
	cdll_destroy(list, del);
	free(list);
	return ;
}

t_cdll	*cdll_create(void)
{
	t_cdll	*list;

	list = ft_calloc(1, sizeof(t_cdll));
	if (!list)
		return (0);
	(*list) = cdll_init();
	return (list);
}
