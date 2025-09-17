/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_clamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:57:57 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:58:06 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

static MYFLOAT	clamp_mf(MYFLOAT value, MYFLOAT min, MYFLOAT max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

t_colourf	colourf_clamp(t_colourf c, t_colourf min, t_colourf max)
{
	t_colourf	result;

	result.r = clamp_mf(c.r, min.r, max.r);
	result.g = clamp_mf(c.g, min.g, max.g);
	result.b = clamp_mf(c.b, min.b, max.b);
	result.a = clamp_mf(c.a, min.a, max.a);
	return (result);
}
