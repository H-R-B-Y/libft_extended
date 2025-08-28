/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spmc_ringbuff_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:37:44 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 15:38:56 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_spmc_ringbuff.h"

u64				spmc_rb_size(t_spmc_ringbuff *ringbuff)
{
	if (!ringbuff)
		return (0);
	return (__sync_fetch_and_or(&ringbuff->size, 0x00));
}
