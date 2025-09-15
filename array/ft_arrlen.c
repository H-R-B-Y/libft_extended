/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:29:32 by hurb              #+#    #+#             */
/*   Updated: 2025/09/10 10:24:01 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

size_t	ft_arrlen(void **chunks)
{
	size_t	i;

	if (!chunks)
		return (0);
	i = 0;
	while (chunks[i])
	{
		if (!chunks[i])
			break ;
		i++;
	}
	return (i);
}
