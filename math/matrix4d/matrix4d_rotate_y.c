/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4d_rotate_y.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:55:22 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:44:42 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4d.h"

t_matrix4d	matrix4d_rotate_y(MYFLOAT angle)
{
	t_matrix4d	matrix;
	MYFLOAT		cos_angle;
	MYFLOAT		sin_angle;

	cos_angle = cosf(angle);
	sin_angle = sinf(angle);
	matrix.x = (t_vec4){.x = cos_angle, .y = 0.0f, .z = sin_angle, .w = 0.0f};
	matrix.y = (t_vec4){.x = 0.0f, .y = 1.0f, .z = 0.0f, .w = 0.0f};
	matrix.z = (t_vec4){.x = -sin_angle, .y = 0.0f, .z = cos_angle, .w = 0.0f};
	matrix.w = (t_vec4){.x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 1.0f};
	return (matrix);
}
