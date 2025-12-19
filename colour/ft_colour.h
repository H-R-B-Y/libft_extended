/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colour.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:15:36 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/19 11:52:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOUR_H
# define FT_COLOUR_H

# include "ft_mem.h"
# include "ft_math.h"
# include "defined.h"

# ifdef ENDIANNESS
#  if ENDIANNESS == 0

typedef union s_colour
{
	struct s_internal_colour_components
	{
		t_u8	b;
		t_u8	g;
		t_u8	r;
		t_u8	a;
	}	c;
	uint32_t	u;
}	t_colour;

typedef struct s_colourf
{
	MYFLOAT	r;
	MYFLOAT	g;
	MYFLOAT	b;
	MYFLOAT	a;
}	t_colourf;

#  else

typedef union s_colour
{
	struct s_internal_colour_components
	{
		t_u8	a;
		t_u8	r;
		t_u8	g;
		t_u8	b;
	}	c;
	uint32_t	u;
}	t_colour;

typedef struct s_colourf
{
	MYFLOAT	a;
	MYFLOAT	r;
	MYFLOAT	g;
	MYFLOAT	b;
}	t_colourf;

#  endif
# else
#  error "Endianness not defined"
# endif

# ifndef COLOUR_MAX
#  warning "compile with -DCOLOUR_MAX='((t_colour){.u = 0xFFFFFFFF})'"
# endif
# ifndef COLOUR_MIN
#  warning "compile with -DCOLOUR_MIN='((t_colour){.u = 0x00000000})'"
# endif
# ifndef COLOURF_MAX
#  warning "compile with -DCOLOURF_MAX='((t_colourf){1.0f, 1.0f, 1.0f, 1.0f})'"
# endif
# ifndef COLOURF_MIN
#  warning "compile with -DCOLOURF_MIN='((t_colourf){0.0f, 0.0f, 0.0f, 0.0f})'"
# endif

/**
 * @brief Add two colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return t_colour 
 */
t_colour	colour_add(t_colour c1, t_colour c2);

/**
 * @brief Create a colour.
 * 
 * @param r red
 * @param g green
 * @param b blue
 * @param a alpha
 * @return t_colour 
 */
t_colour	colour_create(t_u8 r, t_u8 g, t_u8 b, t_u8 a);

/**
 * @brief Multiply two colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return t_colour 
 */
t_colour	colour_multiply(t_colour c1, t_colour c2);

/**
 * @brief Scale a colour by a factor.
 * 
 * @param c colour
 * @param factor scale factor
 * @return t_colour 
 */
t_colour	colour_scale(t_colour c, MYFLOAT factor);

/**
 * @brief Convert a colour to a floating point colour.
 * 
 * @param c colour
 * @return t_colourf 
 */
t_colourf	colour_to_colourf(t_colour c);

/**
 * @brief Linearly interpolate between two colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @param t interpolation factor
 * @return t_colour 
 */
t_colour	colour_lerp(t_colour c1, t_colour c2, MYFLOAT t);

/**
 * @brief Convert a colour to greyscale.
 * 
 * @param c colour
 * @return t_colour 
 */
t_colour	colour_to_greyscale(t_colour c);

/**
 * @brief Invert a colour.
 * 
 * @param c colour
 * @return t_colour 
 */
t_colour	colour_invert(t_colour c);

/**
 * @brief Apply gamma correction to a colour.
 * 
 * @param c colour
 * @param gamma gamma value
 * @return t_colour 
 */
t_colour	colour_gamma_correction(t_colour c, MYFLOAT gamma);

/**
 * @brief 	Clamp a colour between a minimum and maximum value.
 * 
 * @param c colour
 * @param min colour
 * @param max colour
 * @return t_colour 
 */
t_colour	colour_clamp(t_colour c, t_colour min, t_colour max);

/**
 * @brief Adjust the brightness of a colour.
 * 
 * @param c colour
 * @param factor brightness factor
 * @return t_colour 
 */
t_colour	colour_brightness(t_colour c, MYFLOAT factor);

/**
 * @brief Adjust the contrast of a colour.
 * 
 * @param c colour
 * @param factor contrast factor
 * @return t_colour 
 */
t_colour	colour_contrast(t_colour c, MYFLOAT factor);

/**
 * @brief Blend two colours using alpha blending.
 * 
 * @param src source colour
 * @param dst destination colour
 * @return t_colour 
 */
t_colour	colour_blend(t_colour src, t_colour dst);

/**
 * @brief Subtract two colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return t_colour 
 */
t_colour	colour_subtract(t_colour c1, t_colour c2);

/**
 * @brief Calculate the average of two colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return t_colour 
 */
t_colour	colour_average(t_colour c1, t_colour c2);

/**
 * @brief Calculate the Euclidean distance between two colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return MYFLOAT 
 */
MYFLOAT		colour_distance(t_colour c1, t_colour c2);

/**
 * @brief Calculate the squared Euclidean distance between two colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return MYFLOAT 
 */
MYFLOAT		colour_distance_sq(t_colour c1, t_colour c2);

/**
 * @brief Check if two colours are equal.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return int 
 */
int			colour_equal(t_colour c1, t_colour c2);

/**
 * @brief Add two floating point colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return t_colourf 
 */
t_colourf	colourf_add(t_colourf c1, t_colourf c2);

/**
 * @brief Create a floating point colour.
 * 
 * @param r red component
 * @param g green component
 * @param b blue component
 * @param a alpha component
 * @return t_colourf 
 */
t_colourf	colourf_create(MYFLOAT r, MYFLOAT g, MYFLOAT b, MYFLOAT a);

/**
 * @brief Multiply two floating point colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return t_colourf 
 */
t_colourf	colourf_multiply(t_colourf c1, t_colourf c2);

/**
 * @brief Scale a floating point colour by a factor.
 * 
 * @param c colour
 * @param factor scale factor
 * @return t_colourf 
 */
t_colourf	colourf_scale(t_colourf c, MYFLOAT factor);

/**
 * @brief Convert a floating point colour to an integer colour.
 * 
 * @param c colour
 * @return t_colour 
 */
t_colour	colourf_to_colour(t_colourf c);

/**
 * @brief Linearly interpolate between two floating point colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @param t interpolation factor
 * @return t_colourf 
 */
t_colourf	colourf_lerp(t_colourf c1, t_colourf c2, MYFLOAT t);

/**
 * @brief Convert a floating point colour to greyscale using the luminosity
 * method. The alpha channel is preserved.
 * 
 * @param c colour
 * @return t_colourf 
 */
t_colourf	colourf_to_greyscale(t_colourf c);

/**
 * @brief Invert a floating point colour.
 * 
 * @param c colour
 * @return t_colourf 
 */
t_colourf	colourf_invert(t_colourf c);

/**
 * @brief Apply gamma correction to a floating point colour.
 * 
 * @param c colour
 * @param gamma gamma value
 * @return t_colourf 
 */
t_colourf	colourf_gamma_correction(t_colourf c, MYFLOAT gamma);

/**
 * @brief Apply inverse gamma correction to a floating point colour.
 * 
 * @param c colour
 * @param gamma gamma value
 * @return t_colourf 
 */
t_colourf	colourf_clamp(t_colourf c, t_colourf min, t_colourf max);

/**
 * @brief Adjust the brightness of a floating point colour.
 * 
 * @param c colour
 * @param factor brightness factor
 * @return t_colourf 
 */
t_colourf	colourf_brightness(t_colourf c, MYFLOAT factor);

/**
 * @brief Adjust the contrast of a floating point colour.
 * 
 * @param c colour
 * @param factor contrast factor
 * @return t_colourf 
 */
t_colourf	colourf_contrast(t_colourf c, MYFLOAT factor);

/**
 * @brief Blend two floating point colours using alpha blending.
 * 
 * @param src source colour
 * @param dst destination colour
 * @return t_colourf 
 */
t_colourf	colourf_blend(t_colourf src, t_colourf dst);

/**
 * @brief Subtract one floating point colour from another.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return t_colourf 
 */
t_colourf	colourf_subtract(t_colourf c1, t_colourf c2);

/**
 * @brief Calculate the average of two floating point colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return t_colourf 
 */
t_colourf	colourf_average(t_colourf c1, t_colourf c2);

/**
 * @brief Calculate the Euclidean distance between two floating point colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return MYFLOAT 
 */
MYFLOAT		colourf_distance(t_colourf c1, t_colourf c2);

/**
 * @brief 	Calculate the squared Euclidean distance between two floating
 * point colours.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return MYFLOAT 
 */
MYFLOAT		colourf_distance_sq(t_colourf c1, t_colourf c2);

/**
 * @brief Check if two floating point colours are equal.
 * 
 * @param c1 colour 1
 * @param c2 colour 2
 * @return int 
 */
int			colourf_equal(t_colourf c1, t_colourf c2);

#endif
