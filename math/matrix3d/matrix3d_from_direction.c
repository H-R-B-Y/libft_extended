/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3d_from_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:00:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/19 12:01:28 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix3d.h"

t_matrix3d	matrix3d_from_direction(t_vec3 direction)
{
	t_matrix3d	matrix;
	t_vec3		up;
	t_vec3		right;
	t_vec3		forward;

	up = vec3_normalise(direction);
	right = vec3_normalise(vec3_perpendicular(up));
	forward = vec3_normalise(vec3_cross(right, up));
	matrix.x.x = right.x;
	matrix.x.y = right.y;
	matrix.x.z = right.z;
	matrix.y.x = up.x;
	matrix.y.y = up.y;
	matrix.y.z = up.z;
	matrix.z.x = forward.x;
	matrix.z.y = forward.y;
	matrix.z.z = forward.z;
	return (matrix);
}
