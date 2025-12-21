/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:47:45 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

float	colour_distance_sq(t_colour c1, t_colour c2)
{
	float		dr;
	float		dg;
	float		db;

	dr = (float)c1.c.r - (float)c2.c.r;
	dg = (float)c1.c.g - (float)c2.c.g;
	db = (float)c1.c.b - (float)c2.c.b;
	return (dr * dr + dg * dg + db * db);
}

float	colour_distance(t_colour c1, t_colour c2)
{
	return (sqrtf(colour_distance_sq(c1, c2)));
}
