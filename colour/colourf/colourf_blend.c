/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_blend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:57:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:57:47 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colourf_blend(t_colourf src, t_colourf dst)
{
	t_colourf	result;
	MYFLOAT		alpha;

	alpha = src.a;
	result.r = src.r * alpha + dst.r * (1.0f - alpha);
	result.g = src.g * alpha + dst.g * (1.0f - alpha);
	result.b = src.b * alpha + dst.b * (1.0f - alpha);
	result.a = src.a + dst.a * (1.0f - alpha);
	result = colourf_clamp(result, COLOURF_MIN, COLOURF_MAX);
	return (result);
}
