/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:09:55 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/27 20:37:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	const char *lil_i;
	unsigned int offset;

	if (big == 0 || little == 0 || len == 0 || len < ft_strlen(little) || ft_strlen(little) > ft_strlen(big))
		return (0);
	offset = 0;
	lil_i = little;
	while (*lil_i && *lil_i == *(big + offset))
	{
		offset++;
		lil_i++;
	}
	if (*lil_i == '\0')
		return (big);
	else
		return (ft_strnstr(big+1, little, len-1));
}
