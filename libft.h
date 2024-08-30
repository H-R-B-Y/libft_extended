/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:21:04 by hbreeze           #+#    #+#             */
/*   Updated: 2024/08/30 12:15:35 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>

// Mandatory

// Character checks

int				ft_isalpha(int argument);

int				ft_isdigit(int arg);

int				ft_isalnum(int argument);

int				ft_isascii(int c);

int				ft_isprint(int arg);

// Str functions

unsigned int	ft_strlen(const char *str);

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);

int				ft_toupper(int c);

int				ft_tolower(int c);

char			*ft_strchr(const char *s, int c);

char			*ft_strrchr(const char *s, int c);

int				ft_strncmp(const char *s1, const char *s2, unsigned int n);

char			*ft_strnstr(const char *big,
					const char *little, unsigned int len);

char			*ft_strdup(const char *src);

char			*ft_substr(const char *s, unsigned int start, unsigned int len);

char			*ft_strjoin(const char *s1, const char *s2);

char			*ft_strtrim(const char*s1, const char *set);

char			**ft_split(const char *s, char c);

// Memory functions

void			*ft_memset(void *str, int c, int n);

void			ft_bzero(void *s, int n);

void			*ft_memcpy(void *dest, const void *src, int n);

void			*ft_memmove(void *dest, const void *src, unsigned int n);

void			*ft_memchr(const void *s, int c, unsigned int n);

int				ft_memcmp(const void *s1, const void *s2, unsigned int n);

void			*ft_calloc(unsigned int nmemb, unsigned int size);

// Ascii <-> Int functions

int				ft_atoi(const char *nptr);

char			*ft_itoa(int n);

// Iteration

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

// IO

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

// BONUS

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// Creation

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst, t_list *new);

void			ft_lstadd_back(t_list **lst, t_list *new);

// Naviation

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);


// Deletion

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void*));

// Iteration

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *)
					);

#endif