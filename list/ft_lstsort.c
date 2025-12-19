/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:04:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/19 12:11:16 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*split(t_list *lst)
{
	t_list	*fast;
	t_list	*slow;
	t_list	*second;

	if (!lst || !lst->next)
		return (NULL);
	fast = lst;
	slow = lst;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	second = slow->next;
	slow->next = NULL;
	return (second);
}

static t_list	*merge(t_list *left, t_list *right, int (*cmp)(void *, void *))
{
	if (!left)
		return (right);
	if (!right)
		return (left);
	if (cmp(left->content, right->content) <= 0)
	{
		left->next = merge(left->next, right, cmp);
		return (left);
	}
	else
	{
		right->next = merge(left, right->next, cmp);
		return (right);
	}
}

t_list	*ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*second;

	if (!lst || !lst->next)
		return (lst);
	second = split(lst);
	lst = ft_lstsort(lst, cmp);
	second = ft_lstsort(second, cmp);
	return (merge(lst, second, cmp));
}
