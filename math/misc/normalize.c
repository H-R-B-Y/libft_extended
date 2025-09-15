/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:29:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/15 16:47:23 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

MYFLOAT	normalize(MYFLOAT from, MYFLOAT too, MYFLOAT t)
{
	MYFLOAT	range;
	
	range = too - from;
	if (range == 0)
		return (0);
	return ((t - from) / range);
}
