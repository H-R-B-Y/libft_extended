/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:06:09 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 12:34:44 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAP_H
# define HASH_MAP_H

# include <sys/types.h>

# ifndef MAXHASH
#  define MAXHASH 1024
# endif

# include "defined.h"
# include "ft_mem.h"
# define CALLOC ft_calloc

typedef unsigned int (*t_hashfnc)(const void *);
typedef int (*t_hashcmp)(const void *, const void *);
typedef struct s_hashmap	t_hashmap;
typedef struct s_hashpair	t_hashpair;

struct s_hashpair
{
	const void			*key;
	const void			*value;
	struct s_hashpair	*next;
};

int		pair_add_value(t_hashmap *hashmap, t_hashpair *head, void *key, void *value);
void	destroy_pairlist(t_hashpair **pair);

struct s_hashmap
{
	t_hashpair		*pairs[MAXHASH];
	t_hashfnc		hash_key;
	t_hashcmp		hash_cmp;
};

/**
 * @brief Create new hashmap object
 * 
 * @param hashfnc hashing function
 * @param hashcmp hash comparison funciton
 * @return t_hashmap new object with initial values set
 */
t_hashmap	create_hashmap(t_hashfnc hashfnc, t_hashcmp hashcmp);

/**
 * @brief Destroy a hashmap object
 * 
 * @param hashmap the hasmap to destroy
 * @return int not 0 on error
 */
int			destroy_hashmap(t_hashmap *hashmap);

int			hash_add_value(t_hashmap *hashmap,
				void *key, void *value);

void		*hash_get_value(t_hashmap *hashmap, const void *key);


#endif