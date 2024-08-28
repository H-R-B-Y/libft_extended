/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:50:51 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 11:05:14 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	size;

	if (s1 == 0 || s2 == 0)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	output = malloc(size + 1);
	output[size] = '\0';
	if (output == 0)
		return (0);
	ft_strlcat(output, s1, ft_strlen(s1)+1);
	ft_strlcat(output + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (output);
}
