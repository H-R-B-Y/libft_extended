/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:45:48 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/21 18:44:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

float	deg_to_rad(float degrees)
{
	return (degrees * (M_PI / 180.0f));
}

float	rad_to_deg(float radians)
{
	return (radians * (180.0f / M_PI));
}
