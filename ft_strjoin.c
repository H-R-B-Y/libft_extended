/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:50:51 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 20:18:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*output;
	unsigned int	size;
	unsigned int	index;

	if (s1 == 0 || s2 == 0)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	output = malloc(size + 1);
	output[size] = '\0';
	if (output == 0)
		return (0);
	index = 0;
	while (index < ft_strlen(s1))
	{
		output[index] = s1[index];
		index++;
	}
	index = 0;
	while (index < ft_strlen(s2))
	{
		output[ft_strlen(s1) + index] = s2[index];
		index++;
	}
	return (output);
}
