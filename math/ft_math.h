/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:11:38 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/15 16:48:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HB_MATH_EXT_H
# define HB_MATH_EXT_H

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
 * @return MYFLOAT 
 */
MYFLOAT		lerp(MYFLOAT start, MYFLOAT end, MYFLOAT t);

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
 * @return MYFLOAT
 */
MYFLOAT		normalize(MYFLOAT from, MYFLOAT too, MYFLOAT t);

/**
 * @brief Map a value t from one range to another.
 * 
 * @param from The starting range (min, max).
 * @param too The target range (min, max).
 * @param t The value to map.
 * @return MYFLOAT
 */
MYFLOAT		maprange(t_vec2 from, t_vec2 too, MYFLOAT t);

/**
 * @brief Convert degrees to radians.
 * 
 * @param degrees degrees
 * @return MYFLOAT radians
 */
MYFLOAT	deg_to_rad(MYFLOAT degrees);

/**
 * @brief Convert radians to degrees.
 * 
 * @param radians radians
 * @return MYFLOAT degrees
 */
MYFLOAT	rad_to_deg(MYFLOAT radians);

//  ██████  ██████  ██       ██████  ██    ██ ██████  
// ██      ██    ██ ██      ██    ██ ██    ██ ██   ██ 
// ██      ██    ██ ██      ██    ██ ██    ██ ██████  
// ██      ██    ██ ██      ██    ██ ██    ██ ██   ██ 
//  ██████  ██████  ███████  ██████   ██████  ██   ██ 

t_u8	rgba_get_red(t_u32 colour);
t_u8	rgba_get_green(t_u32 colour);
t_u8	rgba_get_blue(t_u32 colour);
t_u8	rgba_get_alph(t_u32 colour);

t_u32	colour_rgba(t_u8 red,
				t_u8 green,
				t_u8 blue,
				t_u8 alpha);

t_u32	lerp_colour(t_u32 from, t_u32 too, float t);

t_u32	parse_rgba_str(const char *rgba);

#endif