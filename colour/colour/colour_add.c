/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:43:41 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:45:08 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_add(t_colour c1, t_colour c2)
{
	t_colour	result;
	t_u16		steps[4];

	steps[0] = (t_u16)c1.c.r + (t_u16)c2.c.r;
	steps[1] = (t_u16)c1.c.g + (t_u16)c2.c.g;
	steps[2] = (t_u16)c1.c.b + (t_u16)c2.c.b;
	steps[3] = (t_u16)c1.c.a + (t_u16)c2.c.a;
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
