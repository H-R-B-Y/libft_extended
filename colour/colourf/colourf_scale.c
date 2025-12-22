/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:01:20 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/22 18:59:15 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colourf_scale(t_colourf c, float factor)
{
	t_colourf	result;

	result.r = c.r * factor;
	result.g = c.g * factor;
	result.b = c.b * factor;
	result.a = c.a * factor;
	result = colourf_clamp(result,
			((t_colourf){0.0f, 0.0f, 0.0f, 0.0f}),
			(t_colourf){1.0f, 1.0f, 1.0f, 1.0f});
	return (result);
}
