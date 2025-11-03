/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:31:35 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 20:00:22 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

t_hashmap	hm_create(t_hashfnc hashfnc, t_hashcmp hashcmp, size_t max_hashes)
{
	return (
		(t_hashmap){
		.hash_cmp = hashcmp,
		.hash_key = hashfnc,
		.pairs = ft_calloc(max_hashes, sizeof(t_hashpair *)),
		.max_hashes = max_hashes
	});
}
