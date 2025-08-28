/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdll.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:02:28 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 13:20:35 by hbreeze          ###   ########.fr       */
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
	/// @brief The head of the cdll
	struct s_cdll_node			*head;
	/// @brief The tail of the cdll
	struct s_cdll_node			*tail;
	/// @brief The count of nodes in the cdll
	size_t						count;
};

struct s_cdll_node
{
	/// @brief Next node
	struct s_cdll_node	*next;
	/// @brief Previous node
	struct s_cdll_node	*prev;
	/// @brief Pointer to data
	void				*data;
};

/// @brief Initiallise a new circular double linked list 
/// @param  
/// @return 
t_cdll				*cdll_init(void);
void				cdll_delete(t_cdll **list,
						void (*del)(void *));

struct s_cdll_node	*cdll_init_node(void *data);
void				cdll_delete_node(struct s_cdll_node **node,
						void (*del)(void *));

size_t				cdll_push_front(t_cdll *list, struct s_cdll_node *node);
size_t				cdll_push_back(t_cdll *list, struct s_cdll_node *node);

struct s_cdll_node	*cdll_pop_front(t_cdll *list);
struct s_cdll_node	*cdll_pop_back(t_cdll *list);

struct s_cdll_node	*cdll_get(t_cdll *stack, size_t i);

#endif
