/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:21:04 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/27 20:40:18 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int				ft_isalpha(int argument);

int				ft_isdigit(int arg);

int				ft_isalnum(int argument);

int				ft_isascii(int c);

int 			ft_isprint( int arg );

int				ft_strlen(const char *str);

void			*ft_memset(void *str, int c, int n);

void			ft_bzero(void *s, int n);

void			*ft_memcpy(void *dest, const void *src, int n);

void			*ft_memmove(void *dest, const void *src, int n);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int				ft_toupper(int c);

int				ft_tolowwer(int c);

char			*ft_strchr(char *s, int c);

char			*ft_strrchr(char *s, int c);

int				ft_strncmp(const char *s1, const char *s2, unsigned int n);

void			*ft_memchr(const void *s, int c, unsigned int n);

int				ft_memcmp(const void *s1, const void *s2, unsigned int n);

char			*ft_strnstr( char *big, const char *little, unsigned int len);

int				ft_atoi(const char *nptr);

#endif