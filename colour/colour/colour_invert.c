/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:50:52 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:51:02 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_invert(t_colour c)
{
	t_colour	result;

	result.c.r = 255 - c.c.r;
	result.c.g = 255 - c.c.g;
	result.c.b = 255 - c.c.b;
	result.c.a = c.c.a;
	return (result);
}
