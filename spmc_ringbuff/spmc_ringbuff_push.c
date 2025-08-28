/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spmc_ringbuff_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:19:55 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 18:05:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_spmc_ringbuff.h"

int				spmc_rb_push(t_spmc_ringbuff *ringbuff, void *content)
{
	u32		tail;
	void	*expected;

	if (!ringbuff)
		return (RETURN_ERROR);
	tail = __atomic_fetch_add(&ringbuff->tail, 1, __ATOMIC_ACQ_REL);
	expected = NULL;
	if (__atomic_compare_exchange_n(&ringbuff->content[tail % SPMC_RINGBUFF_SZ], &expected,
		content, 0, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE))
	{
		__atomic_fetch_add(&ringbuff->size, 1, __ATOMIC_ACQ_REL);
		return (RETURN_OK);
	}
	__atomic_fetch_sub(&ringbuff->tail, 1, __ATOMIC_ACQ_REL);
	return (RETURN_ERROR);
}
