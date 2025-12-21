/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:11:38 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <math.h>

# include "matrix4d.h"
# include "matrix3d.h"
# include "matrix2d.h"
# include "vec2d.h"
# include "vec3d.h"
# include "vec4d.h"

// ███    ███ ██ ███████  ██████ 
// ████  ████ ██ ██      ██      
// ██ ████ ██ ██ ███████ ██      
// ██  ██  ██ ██      ██ ██      
// ██      ██ ██ ███████  ██████ 

/**
 * @brief Linearly interpolate between start and end by t.
 * 
 * @param start 
 * @param end 
 * @param t 
 * @return float 
 */
float		lerp(float start, float end, float t);

/**
 * @brief Return a float value of t normalized between from and too.
 * 
 * example:
 * normalize(10, 20, 15) -> 0.5
 * normalize(10, 20, 10) -> 0
 * normalize(10, 20, 20) -> 1
 * 
 * @param from Smallest value of the range.
 * @param too Largest value of the range.
 * @param t Value to normalize.
 * @return float
 */
float		normalize(float from, float too, float t);

/**
 * @brief Map a value t from one range to another.
 * 
 * @param from The starting range (min, max).
 * @param too The target range (min, max).
 * @param t The value to map.
 * @return float
 */
float		maprange(t_vec2 from, t_vec2 too, float t);

/**
 * @brief Convert degrees to radians.
 * 
 * @param degrees degrees
 * @return float radians
 */
float		deg_to_rad(float degrees);

/**
 * @brief Convert radians to degrees.
 * 
 * @param radians radians
 * @return float degrees
 */
float		rad_to_deg(float radians);

#endif
