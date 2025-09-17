/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_contrast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:58:12 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:58:19 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colourf_contrast(t_colourf c, MYFLOAT factor)
{
	t_colourf	result;
	MYFLOAT		f;

	f = (259.0f * (factor + 255.0f)) / (255.0f * (259.0f - factor));
	result.r = f * (c.r - 0.5f) + 0.5f;
	result.g = f * (c.g - 0.5f) + 0.5f;
	result.b = f * (c.b - 0.5f) + 0.5f;
	result.a = f * (c.a - 0.5f) + 0.5f;
	result = colourf_clamp(result, COLOURF_MIN, COLOURF_MAX);
	return (result);
}
