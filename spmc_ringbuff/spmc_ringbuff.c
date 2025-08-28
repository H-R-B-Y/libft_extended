/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spmc_ringbuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:16:07 by hbreeze           #+#    #+#             */
/*   Updated: 2025/08/28 15:41:44 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_spmc_ringbuff.h"

t_spmc_ringbuff	spmc_rb_create(void)
{
	t_spmc_ringbuff	buff = {0};

	return (buff);
}

void			spmc_rb_destroy(t_spmc_ringbuff *ringbuff)
{
	(void)ringbuff;
}
