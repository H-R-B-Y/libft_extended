/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:52:04 by hbreeze           #+#    #+#             */
/*   Updated: 2025/11/03 19:09:57 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_LIST_INTERNAL_H
# define FREE_LIST_INTERNAL_H

# include "ft_free_list.h"

t_free_list_node	*next_node(t_free_list *list, t_free_list_node *node);
t_free_list_node	*prev_node(t_free_list *list, t_free_list_node *node);

/**
 * @brief Convert an offset to a pointer in the free list.
 * 
 * @note Internal use only. This function assumes the offset is valid.
 * 
 * @param list Pointer to the free list
 * @param offset Offset to convert
 * @return void* Pointer to the memory location, or NULL if the offset is invalid
 */
void				*offset_to_ptr(t_free_list *list, t_u32 offset);

/**
 * @brief Convert a pointer in the free list to an offset.
 * 
 * @note Internal use only. This function assumes the pointer is valid.
 * 
 * @param list Pointer to the free list
 * @param ptr Pointer to the memory location
 * @return t_u32 Offset corresponding to the pointer
 */
t_u32				ptr_to_offset(t_free_list *list, void *ptr);

int					ptr_is_part_of_freelist(t_free_list *list, void *ptr);

int					node_is_contiguous(t_free_list *list,
						t_free_list_node *left, t_free_list_node *right);
int					join_nodes(t_free_list *list,
						t_free_list_node *left, t_free_list_node *right);

#endif
