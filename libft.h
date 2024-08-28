/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:21:04 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/28 14:00:00 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int				ft_isalpha(int argument);

int				ft_isdigit(int arg);

int				ft_isalnum(int argument);

int				ft_isascii(int c);

int 			ft_isprint( int arg );

unsigned int	ft_strlen(const char *str);

void			*ft_memset(void *str, int c, int n);

void			ft_bzero(void *s, int n);

void			*ft_memcpy(void *dest, const void *src, int n);

void			*ft_memmove(void *dest, const void *src, int n);

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);

int				ft_toupper(int c);

int				ft_tolowwer(int c);

char			*ft_strchr(char *s, int c);

char			*ft_strrchr(char *s, int c);

int				ft_strncmp(const char *s1, const char *s2, unsigned int n);

void			*ft_memchr(const void *s, int c, unsigned int n);

int				ft_memcmp(const void *s1, const void *s2, unsigned int n);

char			*ft_strnstr(const char *big, const char *little, unsigned int len);

int				ft_atoi(const char *nptr);

void			*ft_calloc(unsigned int nmemb, unsigned int size);

char			*ft_strdup(char *src);

char			*ft_substr(char const *s, unsigned int start, unsigned int len);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strtrim(char const *s1, char const *set);

char			**ft_split(char const *s, char c);

char			*ft_itoa(int n);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

#endif