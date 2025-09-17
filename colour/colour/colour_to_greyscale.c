/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_to_greyscale.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:52:22 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:54:10 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

/*
Using luminance weights for conversion to greyscale:
- Red: 29.9%
- Green: 58.7%
- Blue: 11.4%

instead of simple average to account for human eye sensitivity.
This gives a more accurate representation of perceived brightness.
*/

t_colour	colour_to_greyscale(t_colour c)
{
	t_colour	result;
	t_u16		grey;

	grey = (t_u16)(0.299f * (MYFLOAT)c.c.r
			+ 0.587f * (MYFLOAT)c.c.g
			+ 0.114f * (MYFLOAT)c.c.b);
	if (grey > 255)
		grey = 255;
	result = colour_create((t_u8)grey, (t_u8)grey, (t_u8)grey, c.c.a);
	return (result);
}
