/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:02:28 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/26 12:23:58 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDLL_H
# define CDLL_H

# include <sys/types.h>
# include <stdlib.h>

# include "ft_mem.h"
# define CALLOC ft_calloc

typedef struct s_cdll		t_cdll;

struct s_cdll
{
	struct s_cdll_node			*head;
	struct s_cdll_node			*tail;
	size_t						count;
};

struct s_cdll_node
{
	struct s_cdll_node	*next;
	struct s_cdll_node	*prev;
	void				*data;
};

t_cdll				*init_cdll(void);
void				delete_cdll(t_cdll **list, void (*del)(void *));

struct s_cdll_node	*init_node(void *data);
void				delete_node(struct s_cdll_node **node, void (*del)(void *));

size_t				cdll_push_front(t_cdll *list, struct s_cdll_node *node);
size_t				cdll_push_back(t_cdll *list, struct s_cdll_node *node);

struct s_cdll_node	*cdll_pop_front(t_cdll *list);
struct s_cdll_node	*cdll_pop_back(t_cdll *list);

struct s_cdll_node	*cdll_get(t_cdll *stack, size_t i);

#endif
