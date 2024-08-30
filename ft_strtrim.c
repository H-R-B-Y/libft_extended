/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:06:22 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/30 13:04:39 by hbreeze          ###   ########.fr       */
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

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t			size;
	char			*end;

	size = 0;
	end = (char *)s1;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup((char *)s1));
	while (*s1 && char_in_str(*s1, set))
		s1++;
	while (*end)
		end++;
	while (*(--end))
		if (!char_in_str(*end, set))
			break ;
	size = (end - s1) + 1;
	return (ft_substr(s1, 0, size));
}
