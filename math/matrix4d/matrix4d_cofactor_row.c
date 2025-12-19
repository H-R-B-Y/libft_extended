/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4d_cofactor_row.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:30:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/19 11:59:13 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4d.h"

MYFLOAT	det3x3(t_vec3 row1, t_vec3 row2, t_vec3 row3)
{
	return (row1.x * (row2.y * row3.z - row2.z * row3.y)
		- row1.y * (row2.x * row3.z - row2.z * row3.x)
		+ row1.z * (row2.x * row3.y - row2.y * row3.x));
}

void	matrix4d_cofactor_row0(t_matrix4d matrix, t_vec4 *row, MYFLOAT det)
{
	row->x = det3x3((t_vec3){{matrix.y.y, matrix.y.z, matrix.y.w}},
			(t_vec3){{matrix.z.y, matrix.z.z, matrix.z.w}},
			(t_vec3){{matrix.w.y, matrix.w.z, matrix.w.w}}
			) / det;
	row->y = -det3x3((t_vec3){{matrix.x.y, matrix.x.z, matrix.x.w}},
			(t_vec3){{matrix.z.y, matrix.z.z, matrix.z.w}},
			(t_vec3){{matrix.w.y, matrix.w.z, matrix.w.w}}
			) / det;
	row->z = det3x3((t_vec3){{matrix.x.y, matrix.x.z, matrix.x.w}},
			(t_vec3){{matrix.y.y, matrix.y.z, matrix.y.w}},
			(t_vec3){{matrix.w.y, matrix.w.z, matrix.w.w}}
			) / det;
	row->w = -det3x3((t_vec3){{matrix.x.y, matrix.x.z, matrix.x.w}},
			(t_vec3){{matrix.y.y, matrix.y.z, matrix.y.w}},
			(t_vec3){{matrix.z.y, matrix.z.z, matrix.z.w}}
			) / det;
}

void	matrix4d_cofactor_row1(t_matrix4d matrix, t_vec4 *row, MYFLOAT det)
{
	row->x = -det3x3(
			(t_vec3){{matrix.y.x, matrix.y.z, matrix.y.w}},
			(t_vec3){{matrix.z.x, matrix.z.z, matrix.z.w}},
			(t_vec3){{matrix.w.x, matrix.w.z, matrix.w.w}}
			) / det;
	row->y = det3x3(
			(t_vec3){{matrix.x.x, matrix.x.z, matrix.x.w}},
			(t_vec3){{matrix.z.x, matrix.z.z, matrix.z.w}},
			(t_vec3){{matrix.w.x, matrix.w.z, matrix.w.w}}
			) / det;
	row->z = -det3x3(
			(t_vec3){{matrix.x.x, matrix.x.z, matrix.x.w}},
			(t_vec3){{matrix.y.x, matrix.y.z, matrix.y.w}},
			(t_vec3){{matrix.w.x, matrix.w.z, matrix.w.w}}
			) / det;
	row->w = det3x3(
			(t_vec3){{matrix.x.x, matrix.x.z, matrix.x.w}},
			(t_vec3){{matrix.y.x, matrix.y.z, matrix.y.w}},
			(t_vec3){{matrix.z.x, matrix.z.z, matrix.z.w}}
			) / det;
}

void	matrix4d_cofactor_row2(t_matrix4d matrix, t_vec4 *row, MYFLOAT det)
{
	row->x = det3x3(
			(t_vec3){{matrix.y.x, matrix.y.y, matrix.y.w}},
			(t_vec3){{matrix.z.x, matrix.z.y, matrix.z.w}},
			(t_vec3){{matrix.w.x, matrix.w.y, matrix.w.w}}
			) / det;
	row->y = -det3x3(
			(t_vec3){{matrix.x.x, matrix.x.y, matrix.x.w}},
			(t_vec3){{matrix.z.x, matrix.z.y, matrix.z.w}},
			(t_vec3){{matrix.w.x, matrix.w.y, matrix.w.w}}
			) / det;
	row->z = det3x3(
			(t_vec3){{matrix.x.x, matrix.x.y, matrix.x.w}},
			(t_vec3){{matrix.y.x, matrix.y.y, matrix.y.w}},
			(t_vec3){{matrix.w.x, matrix.w.y, matrix.w.w}}
			) / det;
	row->w = -det3x3(
			(t_vec3){{matrix.x.x, matrix.x.y, matrix.x.w}},
			(t_vec3){{matrix.y.x, matrix.y.y, matrix.y.w}},
			(t_vec3){{matrix.z.x, matrix.z.y, matrix.z.w}}
			) / det;
}

void	matrix4d_cofactor_row3(t_matrix4d matrix, t_vec4 *row, MYFLOAT det)
{
	row->x = -det3x3(
			(t_vec3){{matrix.y.x, matrix.y.y, matrix.y.z}},
			(t_vec3){{matrix.z.x, matrix.z.y, matrix.z.z}},
			(t_vec3){{matrix.w.x, matrix.w.y, matrix.w.z}}
			) / det;
	row->y = det3x3(
			(t_vec3){{matrix.x.x, matrix.x.y, matrix.x.z}},
			(t_vec3){{matrix.z.x, matrix.z.y, matrix.z.z}},
			(t_vec3){{matrix.w.x, matrix.w.y, matrix.w.z}}
			) / det;
	row->z = -det3x3(
			(t_vec3){{matrix.x.x, matrix.x.y, matrix.x.z}},
			(t_vec3){{matrix.y.x, matrix.y.y, matrix.y.z}},
			(t_vec3){{matrix.w.x, matrix.w.y, matrix.w.z}}
			) / det;
	row->w = det3x3(
			(t_vec3){{matrix.x.x, matrix.x.y, matrix.x.z}},
			(t_vec3){{matrix.y.x, matrix.y.y, matrix.y.z}},
			(t_vec3){{matrix.z.x, matrix.z.y, matrix.z.z}}
			) / det;
}
