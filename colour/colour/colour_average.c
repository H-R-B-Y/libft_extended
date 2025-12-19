/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_average.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:45:16 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:14:43 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_average(t_colour c1, t_colour c2)
{
	t_colour	result;

	result = colour_create((t_u8)(((t_u16)c1.c.r + (t_u16)c2.c.r) / 2),
			(t_u8)(((t_u16)c1.c.g + (t_u16)c2.c.g) / 2),
			(t_u8)(((t_u16)c1.c.b + (t_u16)c2.c.b) / 2),
			(t_u8)(((t_u16)c1.c.a + (t_u16)c2.c.a) / 2));
	return (result);
}
