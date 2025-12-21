/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_invert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:00:41 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:54:27 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colourf_invert(t_colourf c)
{
	t_colourf	result;

	result.r = 1.0f - c.r;
	result.g = 1.0f - c.g;
	result.b = 1.0f - c.b;
	result.a = c.a;
	result = colourf_clamp(result, ((t_colourf){0.0f, 0.0f, 0.0f, 0.0f}), (t_colourf){1.0f, 1.0f, 1.0f, 1.0f});
	return (result);
}
