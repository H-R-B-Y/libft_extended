/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_add_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:38:50 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/20 12:34:31 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

// TODO: Make some list functions so we dont have to do these loops here
// Just like add back and maybe iter or something
int			pair_add_value(t_hashmap *hashmap,
	t_hashpair *head,
	void *key,
	void *value
)
{
	register t_hashpair	*node;

	if (!hashmap || !head || !key)
		return (RETURN_ERROR);
	node = head;
	while (node)
	{
		if (hashmap->hash_cmp(node->key, key) == 0)
		{
			node->value = value;
			return (RETURN_OK);
		}
		node = node->next;
	}
	node = head;
	while (node && node->next)
		node = node->next;
	node->next = CALLOC(1, sizeof(t_hashpair));
	if (!node->next)
		return (RETURN_ERROR);
	(*node->next) = (t_hashpair){.key = key, .value = value, .next = 0};
	return (RETURN_OK);
}

int			hash_add_value(t_hashmap *hashmap, void *key, void *value)
{
	register unsigned int	hash;

	if (!hashmap || !key)
		return (RETURN_ERROR);
	hash = hashmap->hash_key(key) % MAXHASH;
	if (!hashmap->pairs[hash])
	{
		hashmap->pairs[hash] = CALLOC(1, sizeof(t_hashpair));
		if (!hashmap->pairs[hash])
			return (RETURN_ERROR);
		(*hashmap->pairs[hash]) = (t_hashpair){
			.key = key,
			.value = value,
			.next = 0
		};
		return (RETURN_OK);
	}
	return (pair_add_value(hashmap, hashmap->pairs[hash], key, value));
}
