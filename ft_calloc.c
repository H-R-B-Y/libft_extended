/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:58:30 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 15:23:27 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int nmemb, unsigned long size)
{
	unsigned char	*array;
	unsigned long	i;

	if (nmemb == 0 || size == 0)
		return (0);
	array = malloc(sizeof(char) * size * nmemb);
	if (array == 0)
		return (0);
	i = 0;
	while (i < nmemb * size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
