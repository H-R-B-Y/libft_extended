/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_a_checkout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:23:16 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/02 13:57:27 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_alloc_a.h"

static void	*split_and_allocate(
	struct s_alloc_a *alloc_a,
	struct s_alloc_a_node *current,
	struct s_alloc_a_node *prev,
	size_t size
)
{
	struct s_alloc_a_node	*new_node;
	void					*result;
	size_t					old_size;

	old_size = current->size;
	result = (void *)((char *)current + sizeof(struct s_alloc_a_node));
	new_node = (struct s_alloc_a_node *)((char *)result + size);
	new_node->size = old_size - size - sizeof(struct s_alloc_a_node);
	new_node->next = current->next;
	current->size = size;
	if (prev)
		prev->next = new_node;
	else
		alloc_a->free_list = new_node;
	alloc_a->used_memory += size + sizeof(struct s_alloc_a_node);
	return (result);
}

static void	*use_entire_block(
	struct s_alloc_a *alloc_a,
	struct s_alloc_a_node *current,
	struct s_alloc_a_node *prev
)
{
	void	*result;

	result = (void *)((char *)current + sizeof(struct s_alloc_a_node));
	if (prev)
		prev->next = current->next;
	else
		alloc_a->free_list = current->next;
	alloc_a->used_memory += current->size + sizeof(struct s_alloc_a_node);
	return (result);
}

void	*ft_alloc_a_checkout(
	struct s_alloc_a *alloc_a,
	size_t size
)
{
	struct s_alloc_a_node	*current;
	struct s_alloc_a_node	*prev;

	if (!alloc_a || size == 0)
		return (NULL);
	current = alloc_a->free_list;
	prev = NULL;
	while (current)
	{
		if (current->size >= size + sizeof(struct s_alloc_a_node))
			return (split_and_allocate(alloc_a, current, prev, size));
		else if (current->size >= size)
			return (use_entire_block(alloc_a, current, prev));
		prev = current;
		current = current->next;
	}
	return (NULL);
}
