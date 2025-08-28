/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hashmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:33:45 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/20 12:34:31 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"
#include <stdlib.h>

void		destroy_pairlist(t_hashpair **pair)
{
	t_hashpair	*p;

	if (!pair || !*pair)
		return;
	p = *pair;
	if (p->next)
		destroy_pairlist(&p->next);
	free(p);
	*pair = 0;
}

int			destroy_hashmap(t_hashmap *hashmap)
{
	ssize_t	idx;

	if (!hashmap)
		return (RETURN_ERROR);
	idx = 0;
	while (idx < MAXHASH)
	{
		if (hashmap->pairs[idx])
			destroy_pairlist(&hashmap->pairs[idx]);
		idx++;
	}
	return (RETURN_OK);
}
