/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_lerp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:51:04 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:51:24 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_lerp(t_colour c1, t_colour c2, MYFLOAT t)
{
	t_colour	result;
	MYFLOAT		inv_t;

	if (t < 0.0f)
		t = 0.0f;
	if (t > 1.0f)
		t = 1.0f;
	inv_t = 1.0f - t;
	result.c.r = (t_u8)((MYFLOAT)c1.c.r
		* inv_t + (MYFLOAT)c2.c.r * t);
	result.c.g = (t_u8)((MYFLOAT)c1.c.g
		* inv_t + (MYFLOAT)c2.c.g * t);
	result.c.b = (t_u8)((MYFLOAT)c1.c.b
		* inv_t + (MYFLOAT)c2.c.b * t);
	result.c.a = (t_u8)((MYFLOAT)c1.c.a
		* inv_t + (MYFLOAT)c2.c.a * t);
	return (result);
}
