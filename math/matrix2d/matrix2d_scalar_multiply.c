/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2d_scalar_multiply.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:29:01 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix2d.h"

t_matrix2d	matrix2d_scalar_multiply(t_matrix2d mat, float scalar)
{
	t_matrix2d	result;

	result.x.x = mat.x.x * scalar;
	result.x.y = mat.x.y * scalar;
	result.y.x = mat.y.x * scalar;
	result.y.y = mat.y.y * scalar;
	return (result);
}
