/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3d_from_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:00:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/15 17:00:03 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix3d.h"

t_matrix3d	matrix3d_from_direction(t_vec3 direction)
{
	t_matrix3d	matrix;
	t_vec3		forward;
	t_vec3		right;
	t_vec3		up;

	forward = vec3_normalise(direction);
	right = vec3_normalise(vec3_perpendicular(forward));
	up = vec3_normalise(vec3_cross(forward, right));
	matrix.x.x = right.x;
	matrix.x.y = up.x;
	matrix.x.z = forward.x;
	matrix.y.x = right.y;
	matrix.y.y = up.y;
	matrix.y.z = forward.y;
	matrix.z.x = right.z;
	matrix.z.y = up.z;
	matrix.z.z = forward.z;
	return (matrix);
}
