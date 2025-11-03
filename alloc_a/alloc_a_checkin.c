/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_a_checkin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:28:19 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/02 13:57:36 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_alloc_a.h"

static void	find_insertion_point(
	struct s_alloc_a_node *free_list,
	struct s_alloc_a_node *node,
	struct s_alloc_a_node **prev,
	struct s_alloc_a_node **current
)
{
	*prev = NULL;
	*current = free_list;
	while (*current && (void *)(*current) < (void *)node)
	{
		*prev = *current;
		*current = (*current)->next;
	}
}

static void	merge_with_next(
	struct s_alloc_a_node *node,
	struct s_alloc_a_node *current
)
{
	if (current && ((char *)node + sizeof(struct s_alloc_a_node) + node->size) == (char *)current)
	{
		node->size += sizeof(struct s_alloc_a_node) + current->size;
		node->next = current->next;
	}
	else
		node->next = current;
}

static void	merge_with_prev_or_insert(
	struct s_alloc_a *alloc_a,
	struct s_alloc_a_node *node,
	struct s_alloc_a_node *prev
)
{
	if (prev && ((char *)prev + sizeof(struct s_alloc_a_node) + prev->size) == (char *)node)
	{
		prev->size += sizeof(struct s_alloc_a_node) + node->size;
		prev->next = node->next;
	}
	else
	{
		if (prev)
			prev->next = node;
		else
			alloc_a->free_list = node;
	}
}

void	*ft_alloc_a_checkin(
	struct s_alloc_a *alloc_a,
	void *ptr
)
{
	struct s_alloc_a_node	*node;
	struct s_alloc_a_node	*current;
	struct s_alloc_a_node	*prev;
	size_t					freed_size;

	if (!alloc_a || !ptr)
		return (NULL);
	node = (struct s_alloc_a_node *)((char *)ptr - sizeof(struct s_alloc_a_node));
	freed_size = node->size + sizeof(struct s_alloc_a_node);
	find_insertion_point(alloc_a->free_list, node, &prev, &current);
	merge_with_next(node, current);
	merge_with_prev_or_insert(alloc_a, node, prev);
	alloc_a->used_memory -= freed_size;
	return (NULL);
}
