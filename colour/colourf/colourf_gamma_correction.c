/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_gamma_correction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:00:18 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 13:00:30 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colourf_gamma_correction(t_colourf c, MYFLOAT gamma)
{
	t_colourf	result;
	MYFLOAT		inv_gamma;

	if (gamma <= 0.0f)
		gamma = 1.0f;
	inv_gamma = 1.0f / gamma;
	result.r = powf(c.r, inv_gamma);
	result.g = powf(c.g, inv_gamma);
	result.b = powf(c.b, inv_gamma);
	result.a = powf(c.a, inv_gamma);
	result = colourf_clamp(result, COLOURF_MIN, COLOURF_MAX);
	return (result);
}
t_colourf	colourf_inverse_gamma_correction(t_colourf c, MYFLOAT gamma)
{
	t_colourf	result;

	result = colourf_gamma_correction(c, 1.0f / gamma);
	return (result);
}
