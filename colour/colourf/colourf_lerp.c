/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_lerp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:00:59 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 13:01:08 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colourf_lerp(t_colourf c1, t_colourf c2, MYFLOAT t)
{
	t_colourf	result;

	if (t < 0.0f)
		t = 0.0f;
	if (t > 1.0f)
		t = 1.0f;
	result.r = c1.r + (c2.r - c1.r) * t;
	result.g = c1.g + (c2.g - c1.g) * t;
	result.b = c1.b + (c2.b - c1.b) * t;
	result.a = c1.a + (c2.a - c1.a) * t;
	result = colourf_clamp(result, COLOURF_MIN, COLOURF_MAX);
	return (result);
}
