/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_to_colourf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:52:01 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:52:14 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colour_to_colourf(t_colour c)
{
	t_colourf	result;

	result.r = (MYFLOAT)c.c.r / 255.0f;
	result.g = (MYFLOAT)c.c.g / 255.0f;
	result.b = (MYFLOAT)c.c.b / 255.0f;
	result.a = (MYFLOAT)c.c.a / 255.0f;
	return (result);
}
