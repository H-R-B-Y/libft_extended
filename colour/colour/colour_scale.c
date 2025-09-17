/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:51:41 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:51:50 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_scale(t_colour c, MYFLOAT scale)
{
	t_colour	result;
	t_u16		steps[4];

	steps[0] = (t_u16)((MYFLOAT)c.c.r * scale);
	steps[1] = (t_u16)((MYFLOAT)c.c.g * scale);
	steps[2] = (t_u16)((MYFLOAT)c.c.b * scale);
	steps[3] = (t_u16)((MYFLOAT)c.c.a * scale);
	if (steps[0] > 255)
		steps[0] = 255;
	if (steps[1] > 255)
		steps[1] = 255;
	if (steps[2] > 255)
		steps[2] = 255;
	if (steps[3] > 255)
		steps[3] = 255;
	result = colour_create((t_u8)steps[0],
		(t_u8)steps[1], (t_u8)steps[2], (t_u8)steps[3]);
	return (result);
}
