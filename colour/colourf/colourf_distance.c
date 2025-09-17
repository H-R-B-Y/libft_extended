/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:58:38 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:58:48 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

MYFLOAT	colourf_distance_sq(t_colourf c1, t_colourf c2)
{
	MYFLOAT		dr;
	MYFLOAT		dg;
	MYFLOAT		db;

	dr = c1.r - c2.r;
	dg = c1.g - c2.g;
	db = c1.b - c2.b;
	return (dr * dr + dg * dg + db * db);
}
MYFLOAT	colourf_distance(t_colourf c1, t_colourf c2)
{
	return (sqrtf(colourf_distance_sq(c1, c2)));
}
