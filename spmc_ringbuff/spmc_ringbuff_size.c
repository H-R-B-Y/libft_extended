/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spmc_ringbuff_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:37:44 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 17:16:32 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_spmc_ringbuff.h"

u64				spmc_rb_size(t_spmc_ringbuff *ringbuff)
{
	if (!ringbuff)
		return (0);
	return (__atomic_load_n(&ringbuff->size, __ATOMIC_ACQUIRE));
}
