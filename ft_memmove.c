/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:24:59 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/29 17:53:20 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (!src)
		return (0);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (src < dest)
		while (n--)
			temp_dest[n] = temp_src[n];
	return (dest);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include "PRINTMEMORY.c"
// int main ()
// {
// 	char *t = "HELLO WORLD";
// 	char *p;
// 	char *c;

// 	p = malloc (12);
// 	p[11] = '\0';
// 	c = p + 8;
// 	ft_memmove(p, t, 11);
// 	ft_print_memory(p, 128);
// 	ft_memmove(c, p, 11);
// 	ft_print_memory(p, 128);
// }