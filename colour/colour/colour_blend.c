/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_blend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:45:32 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_blend(t_colour src, t_colour dst)
{
	t_colour	result;
	float		alpha;

	alpha = (float)src.c.a / 255.0f;
	result.c.r = (t_u8)((float)src.c.r * alpha
			+ (float)dst.c.r * (1.0f - alpha));
	result.c.g = (t_u8)((float)src.c.g * alpha
			+ (float)dst.c.g * (1.0f - alpha));
	result.c.b = (t_u8)((float)src.c.b * alpha
			+ (float)dst.c.b * (1.0f - alpha));
	result.c.a = (t_u8)(src.c.a + dst.c.a * (1.0f - alpha));
	return (result);
}
