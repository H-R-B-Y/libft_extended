/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spmc_ringbuff_pop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:19:07 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 18:05:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_spmc_ringbuff.h"

int				spmc_rb_pop(t_spmc_ringbuff *ringbuff, void **content)
{
	u32		head;
	void	*stolen;

	if (!ringbuff || !content)
		return (RETURN_ERROR);
	head = __atomic_fetch_add(&ringbuff->head, 1, __ATOMIC_ACQ_REL);
	stolen = __atomic_exchange_n(&ringbuff->content[head % SPMC_RINGBUFF_SZ],
		NULL, __ATOMIC_ACQ_REL);
	if (stolen != NULL)
	{
		*content = stolen;
		__atomic_fetch_sub(&ringbuff->size, 1, __ATOMIC_ACQ_REL);
		return (RETURN_OK);
	}
	__atomic_fetch_sub(&ringbuff->head, 1, __ATOMIC_ACQ_REL);
	return (RETURN_ERROR);
}

