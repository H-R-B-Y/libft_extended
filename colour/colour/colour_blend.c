/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_blend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:45:32 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:45:47 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_blend(t_colour src, t_colour dst)
{
	t_colour	result;
	MYFLOAT		alpha;

	alpha = (MYFLOAT)src.c.a / 255.0f;
	result.c.r = (t_u8)((MYFLOAT)src.c.r * alpha
		+ (MYFLOAT)dst.c.r * (1.0f - alpha));
	result.c.g = (t_u8)((MYFLOAT)src.c.g * alpha
		+ (MYFLOAT)dst.c.g * (1.0f - alpha));
	result.c.b = (t_u8)((MYFLOAT)src.c.b * alpha
		+ (MYFLOAT)dst.c.b * (1.0f - alpha));
	result.c.a = (t_u8)(src.c.a + dst.c.a * (1.0f - alpha));
	return (result);
}
