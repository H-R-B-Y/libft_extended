/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3d_from_direction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:00:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/15 16:55:39 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix3d.h"

/**
 * @brief Create a rotation matrix from a direction vector
 * 
 * This function creates a rotation matrix that aligns the Z-axis with the given
 * direction vector. It constructs an orthogonal basis using the direction as
 * the Z-axis and two perpendicular vectors for X and Y axes.
 * 
 * @param direction Normalized direction vector (forward direction)
 * @return t_matrix3d Rotation matrix that transforms from local to world space
 */
t_matrix3d	matrix3d_from_direction(t_vec3 direction)
{
	t_matrix3d	matrix;
	t_vec3		forward, right, up;

	// Normalize the direction vector (Z-axis)
	forward = vec3_normalise(direction);
	
	// Find a vector perpendicular to the direction
	right = vec3_perpendicular(forward);
	right = vec3_normalise(right);
	
	// Calculate the up vector as the cross product of forward and right
	up = vec3_cross(forward, right);
	up = vec3_normalise(up);
	
	// Build the rotation matrix with the orthogonal basis
	// Each row represents how the standard basis vectors (X, Y, Z) 
	// are transformed in the new coordinate system
	matrix.x.x = right.x;    matrix.x.y = up.x;    matrix.x.z = forward.x;
	matrix.y.x = right.y;    matrix.y.y = up.y;    matrix.y.z = forward.y;
	matrix.z.x = right.z;    matrix.z.y = up.z;    matrix.z.z = forward.z;
	
	return (matrix);
}
