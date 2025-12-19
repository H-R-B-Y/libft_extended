/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2d_identity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:11:27 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/19 12:11:28 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix2d.h"

t_matrix2d	matrix2d_identity(void)
{
	t_matrix2d	result;

	result = (t_matrix2d){{
		.x = (t_vec2){.x = 1, .y = 0},
		.y = (t_vec2){.x = 0, .y = 1}
	}};
	return (result);
}
