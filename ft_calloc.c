/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:58:30 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/29 19:41:01 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*array;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (0);
	if (size && __INT_MAX__/size < nmemb)
		return (0);
	array = malloc(size * nmemb);
	if (array == 0)
		return (0);
	ft_bzero(array, nmemb * size);
	return (array);
}
