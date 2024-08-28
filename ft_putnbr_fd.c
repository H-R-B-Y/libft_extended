/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:22:37 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 15:09:36 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	t;

	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	t = (n % 10) + '0';
	write(fd, &t, 1);
	return ;
}
