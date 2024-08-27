/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:28:16 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/27 19:36:26 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *s, int c)
{
	char *start;

	if (*s == '\0')
		return (0);
	start = s;
	while (*s)
		s++;
	s--;
	while (start <= s && *s != c)
		s--;
	if (start > s)
		return (0);
	return (s);
}
