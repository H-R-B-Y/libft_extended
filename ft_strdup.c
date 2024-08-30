/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:08:45 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/30 13:04:03 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		len;
	size_t		i;
	char		*ret;

	if (!src)
		return (0);
	len = ft_strlen(src);
	ret = malloc((unsigned long)len + 1);
	if (ret == 0)
		return (0);
	i = 0;
	ret[len] = '\0';
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	return (ret);
}
