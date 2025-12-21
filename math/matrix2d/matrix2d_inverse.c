/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2d_inverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:29:01 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix2d.h"

t_matrix2d	matrix2d_inverse(t_matrix2d mat)
{
	t_matrix2d	result;
	float		det;

	det = matrix2d_determinant(mat);
	if (det == 0)
		return ((t_matrix2d){0});
	result.x.x = mat.y.y / det;
	result.x.y = -mat.x.y / det;
	result.y.x = -mat.y.x / det;
	result.y.y = mat.x.x / det;
	return (result);
}
