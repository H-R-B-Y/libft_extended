/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:10:13 by hbreeze           #+#    #+#             */
/*   Updated: 2025/10/05 19:28:21 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

void	hm_remove_pair(t_hashmap *hashmap, const void *key)
{
	size_t		hash;
	t_hashpair	*current;
	t_hashpair	*previous;

	if (!hashmap || !key)
		return ;
	hash = hashmap->hash_key(key) % hashmap->max_hashes;
	current = hashmap->pairs[hash];
	previous = NULL;
	while (current)
	{
		if (hashmap->hash_cmp(current->key, key) == 0)
		{
			if (previous)
				previous->next = current->next;
			else
				hashmap->pairs[hash] = current->next;
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}
