/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:08:45 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 14:17:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*ret;

	len = ft_strlen(src);
	ret = malloc((unsigned long)len + 1);
	if (ret == 0)
		return (0);
	i = 0;
	ret[len] = '\0';
	while (*src)
		ret[i++] = *src++;
	return (ret);
}
