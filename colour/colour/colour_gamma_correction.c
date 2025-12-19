/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_gamma_correction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:49:05 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:15:01 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_gamma_correction(t_colour c, MYFLOAT gamma)
{
	t_colour	result;
	t_u16		steps[4];
	MYFLOAT		inv_gamma;

	if (gamma <= 0.0f)
		gamma = 0.01f;
	inv_gamma = 1.0f / gamma;
	steps[0] = (t_u16)(powf((MYFLOAT)c.c.r / 255.0f, inv_gamma) * 255.0f);
	steps[1] = (t_u16)(powf((MYFLOAT)c.c.g / 255.0f, inv_gamma) * 255.0f);
	steps[2] = (t_u16)(powf((MYFLOAT)c.c.b / 255.0f, inv_gamma) * 255.0f);
	steps[3] = (t_u16)(powf((MYFLOAT)c.c.a / 255.0f, inv_gamma) * 255.0f);
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
