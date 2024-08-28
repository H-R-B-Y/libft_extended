/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:17:48 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 14:01:50 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	unsigned int	length;
	char			*output;

	length = ft_strlen(s);
	index = 0;
	output = malloc(length + 1);
	if (!output || !s || !f)
		return (0);
	output[length] = '\0';
	while (index < length)
	{
		output[index] = f(index, s[index]);
		index++;
	}
	return (output);
}
