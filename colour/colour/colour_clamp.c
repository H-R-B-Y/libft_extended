/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_clamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:46:20 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:47:20 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

static t_u8	clamp_u8(t_u8 value, t_u8 min, t_u8 max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

t_colour	colour_clamp(t_colour c, t_colour min, t_colour max)
{
	t_colour	result;

	result.c.r = clamp_u8(c.c.r, min.c.r, max.c.r);
	result.c.g = clamp_u8(c.c.g, min.c.g, max.c.g);
	result.c.b = clamp_u8(c.c.b, min.c.b, max.c.b);
	result.c.a = clamp_u8(c.c.a, min.c.a, max.c.a);
	return (result);
}
