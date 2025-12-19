/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex_of.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:12:52 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/07 13:25:50 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

ssize_t	ft_lstindex_of(
	t_list *head,
	t_list *node
)
{
	ssize_t	idx;
	t_list	*current;

	if (!head || !node)
		return (-1);
	if (head == node)
		return (0);
	current = head;
	idx = 0;
	while (current && current != node && ++idx)
		current = current->next;
	if (!current || current != node)
		return (-1);
	return (idx);
}

ssize_t	ft_lstindex_of_content(
	t_list *head,
	void *content
)
{
	ssize_t	idx;
	t_list	*current;

	if (!head || !content)
		return (-1);
	if (head->content == content)
		return (0);
	idx = 0;
	current = head;
	while (current && current->content != content && ++idx)
		current = current->next;
	if (!current || current->content != content)
		return (-1);
	return (idx);
}
