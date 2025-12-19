/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_contrast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:47:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:14:54 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_contrast(t_colour c, MYFLOAT factor)
{
	t_colour	result;
	t_u16		steps[4];
	MYFLOAT		f;

	f = (259.0f * (factor + 255.0f)) / (255.0f * (259.0f - factor));
	steps[0] = (t_u16)(f * ((MYFLOAT)c.c.r - 128.0f) + 128.0f);
	steps[1] = (t_u16)(f * ((MYFLOAT)c.c.g - 128.0f) + 128.0f);
	steps[2] = (t_u16)(f * ((MYFLOAT)c.c.b - 128.0f) + 128.0f);
	steps[3] = (t_u16)(f * ((MYFLOAT)c.c.a - 128.0f) + 128.0f);
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
