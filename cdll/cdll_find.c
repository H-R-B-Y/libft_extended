/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:13:54 by hbreeze           #+#    #+#             */
/*   Updated: 2025/10/05 19:14:18 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdll.h"

struct s_cdll_node	*cdll_find(t_cdll *list, void *data,
						int (*cmp)(void *, void *))
{
	struct s_cdll_node	*current;
	size_t				i;

	if (!list || !list->head || !data || !cmp)
		return (0);
	current = list->head;
	i = 0;
	while (i < list->count)
	{
		if (cmp(current->data, data) == 0)
			return (current);
		current = current->next;
		i++;
	}
	return (0);
}
