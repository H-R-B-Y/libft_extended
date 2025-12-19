/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_to_colour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:01:34 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:13:40 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colourf_to_colour(t_colourf c)
{
	t_colour	result;
	t_u16		steps[4];

	steps[0] = (t_u16)(c.r * 255.0f);
	steps[1] = (t_u16)(c.g * 255.0f);
	steps[2] = (t_u16)(c.b * 255.0f);
	steps[3] = (t_u16)(c.a * 255.0f);
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
