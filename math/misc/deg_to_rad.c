/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:45:48 by hbreeze           #+#    #+#             */
/*   Updated: 2025/09/15 16:46:01 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

MYFLOAT	deg_to_rad(MYFLOAT degrees)
{
	return (degrees * (M_PI / 180.0f));
}

MYFLOAT	rad_to_deg(MYFLOAT radians)
{
	return (radians * (180.0f / M_PI));
}
