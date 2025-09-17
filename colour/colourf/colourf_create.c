/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colourf_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:58:26 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/17 12:58:35 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colour.h"

t_colourf	colourf_create(MYFLOAT r, MYFLOAT g, MYFLOAT b, MYFLOAT a)
{
	t_colourf	result;

	result.r = r;
	result.g = g;
	result.b = b;
	result.a = a;
	return (result);
}
