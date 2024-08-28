/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:59:41 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 15:08:04 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	digits_needed(long n)
{
	unsigned long	digits;
	int				i;

	digits = 1;
	i = 0;
	while (digits <= (unsigned long)n)
	{
		digits *= 10;
		i++;
	}
	return (i + !(n));
}

char	*ft_itoa(int n)
{
	unsigned int	digits;
	char			*output;

	digits = digits_needed(n);
	output = malloc(digits + 1);
	if (!output)
		return (0);
	output[digits--] = '\0';
	while (n / 10 > 0)
	{
		output[digits--] = (n % 10) + '0';
		n /= 10;
	}
	output[digits] = (n % 10) + '0';
	return (output);
}
