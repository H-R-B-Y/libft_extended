/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:06:22 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 14:00:19 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	char_in_str(const char c, const char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char			*start; 
	char			*output;
	unsigned int	index;
	unsigned int	rev_i;

	index = 0;
	while (*(s1 + index) && char_in_str(*(s1 + index), set))
		index++;
	if (*(s1 + index) == '\0')
		return (0);
	start = (char *)s1 + index;
	rev_i = ft_strlen(start) - 1;
	while (char_in_str(*(start + rev_i), set) && rev_i > 0)
		rev_i--;
	rev_i += 1;
	output = malloc(rev_i + 1);
	output[rev_i] = '\0';
	ft_strlcat(output, start, rev_i + 1);
	return output;
}
