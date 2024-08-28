/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:30:04 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 11:58:51 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	word_count (const char *str, char sep)
{
	unsigned int	count;
	int				last_sep;
	int				index;

	count = 0;
	last_sep = -1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == sep)
		{
			if (index - last_sep > 1)
				count++;
			last_sep = index;
		}
		index++;
	}
	if (index - last_sep > 1)
		count += 1;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	word;
	unsigned int	count;
	char			**output;
	int				last_sep;
	int				index;

	last_sep = -1;
	count = word_count(s, c);
	output = malloc(sizeof(char *) * (count + 1));
	output[count] = 0;
	index = 0;
	word = 0;
	while (word < count && output)
	{
		if (s[index] != c && s[index] != '\0' && ++index)
			continue ;
		if ((index - last_sep) > 1)
		{
			output[word] = malloc(sizeof(char) * (index - (last_sep + 1) + 1));
			ft_strlcat(output[word], s + last_sep + 1, (index - last_sep));
			word++;
		}
		last_sep = index++;
	}
	return (output);
}
