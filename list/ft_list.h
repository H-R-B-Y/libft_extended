/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:22:09 by hbreeze           #+#    #+#             */
/*   Updated: 2025/12/07 13:28:27 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <sys/types.h>
# include "ft_mem.h"

/**
 * @brief Linked list
 * @param content Pointer to the content of the list item
 * @param next Pointer to the next list item or 0
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/**
 * @brief Create a new list item
 * @param content Pointer to the content of the list item
 * @return Pointer to the new list item or 0 if malloc fails
 */
t_list			*ft_lstnew(void *content);

/**
 * @brief Add a new list item to the front of a list
 * @param lst Pointer to the list
 * @param new Pointer to the new list item
 */
void			ft_lstadd_front(t_list **lst, t_list *new_node);

/**
 * @brief Add a new list item to the back of a list
 * @param lst Pointer to the list
 * @param new Pointer to the new list item
 */
void			ft_lstadd_back(t_list **lst, t_list *new_node);

// Naviation

/**
 * @brief Get the length of a list
 * @param lst Pointer to the list
 */
int				ft_lstsize(t_list *lst);

/**
 * @brief Get the last list item
 * @param lst Pointer to the list
 * @return Pointer to the last list item
 */
t_list			*ft_lstlast(t_list *lst);

/**
 * @brief Pop a node from the list lst
 * 
 * @param lst Pointer to the head of the list to pop from 
 * @return t_list* node popped from the list
 */
t_list			*ft_lstpop_back(t_list **lst);

/**
 * @brief Pop a node from the front of a list
 * 
 * The head of the list will be incremented to the next value
 * 
 * @param lst Pointer to the head of the list to pop from 
 * @return t_list* The node popped from the list
 */
t_list			*ft_lstpop_front(t_list **lst);

// Deletion

/**
 * @brief Delete a list item
 * @param lst Pointer to the list item
 * @param del Function to delete the content of the list item
 */
void			ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Delete all list items
 * @param lst Pointer to the list
 */
void			ft_lstclear(t_list **lst, void (*del)(void*));

// Iteration

/**
 * @brief Iterate over a list applying a function to each list item
 * @param lst Pointer to the list
 * @param f Function to apply to the content of each list item
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterate over a list applying a function to each list item
 * @param lst Pointer to the list
 * @param f Function to apply to the content of each list item
 * @return A new list containing the result of f applied to each list item
 */
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/**
 * @brief Get a list item by index
 * @param lst Pointer to the list
 * @param index Index of the list item
 * @return Pointer to the list item or 0 if the index is out of bounds
 */
t_list			*ft_lstget(t_list *lst, size_t index);

/**
 * @brief Convert a linked list into an array
 * 
 * @param lst The list to convert to an array
 * @return void** allocated array of values from the list
 * @warning Heap allocation of the array pointer
 */
void			**ft_lstarr(t_list *lst);

/**
 * @brief Function to iterate over a list with a parameter
 * @param lst Pointer to the list
 * @param f Function to apply to the content of each list item
 * @param param Parameter to pass to the function
 */
void			ft_lstiter_param(t_list *lst,
					void (*f)(void *, void *),
					void *param);

/**
 * @brief Sort a list (merge sort)
 * @param lst Pointer to the list
 * @param cmp Function to compare lst contents
 * @return t_list head of sorted list
 */
t_list			*ft_lstsort(t_list *lst, int (*cmp)(void *, void *));

/**
 * @brief Function to get previous node from a list
 * @param head the head of the list to search
 * @param node the node to find the previous node from
 * @return t_list * the node previous to node arg, or NULL
 */
t_list			*ft_lstget_prev(t_list *head,
					t_list *node);

/**
 * @brief Get the index of the node node in the list head
 * 
 * @param head The head of the list to search
 * @param node The node to get the index for
 * @return ssize_t Either the index of the search node or -1
 */
ssize_t			ft_lstindex_of(
					t_list *head, t_list *node);

/**
 * @brief Get the index of the node whos content is equal to content
 * 
 * @param head The head of the list to search
 * @param content The content to search for
 * @return ssize_t Either the index of the node whos content matches or -1
 */
ssize_t			ft_lstindex_of_content(
					t_list *head, void *content);

#endif
