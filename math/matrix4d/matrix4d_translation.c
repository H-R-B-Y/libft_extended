/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4d_translation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:56:56 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:45:20 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4d.h"

t_matrix4d	matrix4d_translation(MYFLOAT x, MYFLOAT y, MYFLOAT z, MYFLOAT w)
{
	t_matrix4d	matrix;

	(void)w;
	matrix.x = (t_vec4){.v = {1.0f, 0.0f, 0.0f, x}};
	matrix.y = (t_vec4){.v = {0.0f, 1.0f, 0.0f, y}};
	matrix.z = (t_vec4){.v = {0.0f, 0.0f, 1.0f, z}};
	matrix.w = (t_vec4){.v = {0.0f, 0.0f, 0.0f, 1.0f}};
	return (matrix);
}
