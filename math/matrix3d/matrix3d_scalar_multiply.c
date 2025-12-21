/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3d_scalar_multiply.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:35:27 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix3d.h"

t_matrix3d	matrix3d_scalar_multiply(t_matrix3d mat, float scalar)
{
	t_matrix3d	result;

	result.x.x = mat.x.x * scalar;
	result.x.y = mat.x.y * scalar;
	result.x.z = mat.x.z * scalar;
	result.y.x = mat.y.x * scalar;
	result.y.y = mat.y.y * scalar;
	result.y.z = mat.y.z * scalar;
	result.z.x = mat.z.x * scalar;
	result.z.y = mat.z.y * scalar;
	result.z.z = mat.z.z * scalar;
	return (result);
}
