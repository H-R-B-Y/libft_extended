/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spmc_ringbuff_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:19:55 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 15:43:20 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_spmc_ringbuff.h"

int				spmc_rb_push(t_spmc_ringbuff *ringbuff, void *content)
{
	u32	tail;

	if (!ringbuff)
		return (RETURN_ERROR);
	tail = __sync_fetch_and_add(&ringbuff->tail, 1) % SPMC_RINGBUFF_SZ;
	if (ringbuff->content[tail].valid)
	{
		__sync_sub_and_fetch(&ringbuff->tail, 1);
		return (RETURN_ERROR);
	}
	else
	{
		__sync_synchronize();
		ringbuff->content[tail]
			= (t_spmc_rb_node){.content = content, .valid = 1};
		__sync_add_and_fetch(&ringbuff->size, 1);
	}
	return (RETURN_OK);
}
