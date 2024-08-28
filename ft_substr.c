/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:37:06 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 15:07:42 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*output;
	unsigned int	index;

	index = 0;
	if (!len)
		return (0);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s);
	output = malloc(len + 1);
	if (output == 0)
		return (0);
	output[len] = '\0';
	while (index < len)
	{
		output[index] = s[start + index];
		index++;
	}
	return (output);
}
