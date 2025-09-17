/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_multiply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:01:12 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 13:01:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colourf_multiply(t_colourf c1, t_colourf c2)
{
	t_colourf	result;

	result.r = c1.r * c2.r;
	result.g = c1.g * c2.g;
	result.b = c1.b * c2.b;
	result.a = c1.a * c2.a;
	result = colourf_clamp(result, COLOURF_MIN, COLOURF_MAX);
	return (result);
}
