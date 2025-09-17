/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:58:50 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 13:00:14 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

// account for epsilon?

int	colourf_equal(t_colourf c1, t_colourf c2)
{
	if (c1.r - c2.r < EPSILON && c1.r - c2.r > -EPSILON
		&& c1.g - c2.g < EPSILON && c1.g - c2.g > -EPSILON
		&& c1.b - c2.b < EPSILON && c1.b - c2.b > -EPSILON
		&& c1.a - c2.a < EPSILON && c1.a - c2.a > -EPSILON)
		return (1);
	return (0);
}
