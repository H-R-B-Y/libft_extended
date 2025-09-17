/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:47:45 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:48:25 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

MYFLOAT	colour_distance_sq(t_colour c1, t_colour c2)
{
	MYFLOAT		dr;
	MYFLOAT		dg;
	MYFLOAT		db;

	dr = (MYFLOAT)c1.c.r - (MYFLOAT)c2.c.r;
	dg = (MYFLOAT)c1.c.g - (MYFLOAT)c2.c.g;
	db = (MYFLOAT)c1.c.b - (MYFLOAT)c2.c.b;
	return (dr * dr + dg * dg + db * db);
}

MYFLOAT	colour_distance(t_colour c1, t_colour c2)
{
	return (sqrtf(colour_distance_sq(c1, c2)));
}


