/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:47:38 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:47:43 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colour	colour_create(t_u8 r, t_u8 g, t_u8 b, t_u8 a)
{
	t_colour	result;

	result.c.r = r;
	result.c.g = g;
	result.c.b = b;
	result.c.a = a;
	return (result);
}
