/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:00:07 by hbreeze           #+#    #+#             */
/*   Updated: 2025/10/11 13:01:47 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memdup(void *src, size_t size)
{
	char	*dest;

	if (!src || size == 0)
		return (0);
	dest = ft_calloc(1, size);
	if (!dest)
		return (0);
	ft_memmove(dest, src, size);
	return (dest);
}
