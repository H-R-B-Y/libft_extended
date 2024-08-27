/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:44:05 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/27 19:53:48 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int index;

	if (s == 0)
		return (0);
	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == c)
			return (&(((unsigned char *)s)[index]));
		index++;
	}
	return (0);
}
