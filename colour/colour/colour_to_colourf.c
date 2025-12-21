/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_to_colourf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:52:01 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colour_to_colourf(t_colour c)
{
	t_colourf	result;

	result.r = (float)c.c.r / 255.0f;
	result.g = (float)c.c.g / 255.0f;
	result.b = (float)c.c.b / 255.0f;
	result.a = (float)c.c.a / 255.0f;
	return (result);
}
