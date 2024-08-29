/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:18:08 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/29 13:10:04 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*index;
	
	index = lst;
	if (!lst)
		return (0);
	while (index->next)
		index = index->next;
	return (index);
}

// #include "PRINTMEMORY.c"
// int main()
// {
// 	t_list *start;
// 	char *t = "HELLO WORLD";
// 	char *t1 = "NEW TEXT";
// 	char *t2 = "BORN2CODE";

// 	start = ft_lstnew(t);
// 	start->next = ft_lstnew(t1);
// 	start->next->next = ft_lstnew(t2);
// 	ft_print_memory(ft_lstlast(start)->content, 128);
// }