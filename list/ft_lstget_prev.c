/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_prev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:17:02 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/07 13:26:00 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstget_prev(t_list *head, t_list *node)
{
	t_list	*current;
	t_list	*prev;

	if (!head)
		return (NULL);
	if (!head->next)
		return (head);
	if (node == head)
		return (ft_lstlast(head));
	current = head;
	prev = NULL;
	while (current && current != node)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return (NULL);
	return (prev);
}
