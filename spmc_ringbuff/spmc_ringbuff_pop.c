/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spmc_ringbuff_pop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:19:07 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 15:43:42 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_spmc_ringbuff.h"

int				spmc_rb_pop(t_spmc_ringbuff *ringbuff, void **content)
{
	u32	head;

	if (!ringbuff)
		return (RETURN_ERROR);
	head = __sync_fetch_and_add(&ringbuff->head, 1) % SPMC_RINGBUFF_SZ;
	if (!ringbuff->content[head].valid)
	{
		__sync_sub_and_fetch(&ringbuff->head, 1);
		return (RETURN_ERROR);
	}
	else
	{
		*content = ringbuff->content[head].content;
		__sync_synchronize();
		ringbuff->content[head].valid = 0;
		__sync_sub_and_fetch(&ringbuff->size, 1);
	}
	return (RETURN_OK);
}

