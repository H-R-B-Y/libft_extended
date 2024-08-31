/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:18:30 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/31 13:12:45 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	size_t		i;

	if (!dest || !src)
		return (0);
	i = 0;
	d = dest;
	while (i < n)
	{
		d[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
