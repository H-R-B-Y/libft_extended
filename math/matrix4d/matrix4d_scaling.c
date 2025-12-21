/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4d_scaling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:56:16 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4d.h"

t_matrix4d	matrix4d_scaling(
	float scale_x,
	float scale_y,
	float scale_z,
	float scale_w
)
{
	t_matrix4d	matrix;

	matrix.x = (t_vec4){.x = scale_x, 0.0f, 0.0f, 0.0f};
	matrix.y = (t_vec4){.x = 0.0f, scale_y, 0.0f, 0.0f};
	matrix.z = (t_vec4){.x = 0.0f, 0.0f, scale_z, 0.0f};
	matrix.w = (t_vec4){.x = 0.0f, 0.0f, 0.0f, scale_w};
	return (matrix);
}
