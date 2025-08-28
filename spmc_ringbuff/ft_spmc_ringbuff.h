/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spmc_ringbuff.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:47:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 15:41:44 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __GNU_SOURCE
#  define __GNU_SOURCE
# endif

#ifndef FT_SPMC_RINGBUFF_H
# define FT_SPMC_RINGBUFF_H

# include "ft_mem.h"
# include "defined.h"

# ifndef SPMC_RINGBUFF_SZ
#  define SPMC_RINGBUFF_SZ 1024
# endif

typedef struct s_spmc_rb_node	t_spmc_rb_node;
struct	s_spmc_rb_node
{
	void	*content;
	vu8		valid;
};

typedef struct s_spmc_ringbuff	t_spmc_ringbuff;
// typedef struct s_spmc_ringbuff	t_spmcrbuff;
struct s_spmc_ringbuff
{
	t_spmc_rb_node	content[SPMC_RINGBUFF_SZ];
	vu32			head;
	vu32			tail;
	vu32			size;

};

/**
 * @brief initialise a new ringbuffer
 * 
 * @note: just returns the default values in a struct for copying
 * 
 * @return t_spmc_ringbuff 
 */
t_spmc_ringbuff	spmc_rb_create(void);

/**
 * @brief Destory a ring buffer
 * 
 * @note: Not sure if this should take any destructor
 * functions for the contents of the nodes
 * 
 * @param ringbuff 
 */
void			spmc_rb_destroy(t_spmc_ringbuff *ringbuff);

int				spmc_rb_push(t_spmc_ringbuff *ringbuff, void *content);
int				spmc_rb_pop(t_spmc_ringbuff *ringbuff, void **content);

u64				spmc_rb_size(t_spmc_ringbuff *s_spmc_ringbuff);

#endif
