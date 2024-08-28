/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:24:59 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 14:48:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	index;
	char			*temp_dest;
	char			*temp_src;

	temp_dest = (char *)dest;
	temp_src = (char *)src;
	index = 0;
	while (index < n)
	{
		temp_dest[index] = temp_src[index];
		index++;
	}
	return (dest);
}
