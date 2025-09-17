/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_to_greyscale.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:01:46 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 13:01:59 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

/*
 * Convert a colourf to greyscale using the luminosity method.
 * The alpha channel is preserved.
 */
t_colourf	colourf_to_greyscale(t_colourf c)
{
	MYFLOAT		grey;

	grey = 0.2126f * c.r + 0.7152f * c.g + 0.0722f * c.b;
	return (colourf_create(grey, grey, grey, c.a));
}
