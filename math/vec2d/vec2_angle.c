/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:57:59 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2d.h"

float	vec2_angle(t_vec2 vec1, t_vec2 vec2)
{
	float	dot_product;
	float	magnitude1;
	float	magnitude2;
	float	angle;

	dot_product = vec2_dot_product(vec1, vec2);
	magnitude1 = vec2_magnitude(vec1);
	magnitude2 = vec2_magnitude(vec2);
	if (magnitude1 == 0 || magnitude2 == 0)
		return (0);
	dot_product = dot_product / (magnitude1 * magnitude2);
	if (dot_product > 1.0)
		dot_product = 1.0;
	else if (dot_product < -1.0)
		dot_product = -1.0;
	angle = acos(dot_product);
	return (angle);
}
