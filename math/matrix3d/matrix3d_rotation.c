/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3d_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:42:41 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/15 16:45:05 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
assume radians
*/
t_matrix3d	matrix3d_rotation(t_vec3 rotation)
{
	t_matrix3d res[4];
	MYFLOAT	angles[6];

	angles[0] = cosf(rotation.x);
	angles[1] = sinf(rotation.x);
	angles[2] = cosf(rotation.y);
	angles[3] = sinf(rotation.y);
	angles[4] = cosf(rotation.z);
	angles[5] = sinf(rotation.z);
	res[0] = (t_matrix3d){{{1, 0, 0},
		{0, angles[0], -angles[1]}, {0, angles[1], angles[0]}}};
	res[1] = (t_matrix3d){{{angles[2], 0, angles[3]},
		{0, 1, 0}, {-angles[3], 0, angles[2]}}};
	res[2] = (t_matrix3d){{{angles[4], -angles[5], 0},
		{angles[5], angles[4], 0}, {0, 0, 1}}};
	res[3] = matrix3d_multiply(res[2], matrix3d_multiply(res[1], res[0]));
	return (res[3]);
}