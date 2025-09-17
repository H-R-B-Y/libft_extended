/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_average.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:57:29 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:57:37 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colourf_average(t_colourf c1, t_colourf c2)
{
	t_colourf	result;

	result.r = (c1.r + c2.r) / 2.0f;
	result.g = (c1.g + c2.g) / 2.0f;
	result.b = (c1.b + c2.b) / 2.0f;
	result.a = (c1.a + c2.a) / 2.0f;
	return (result);
}
