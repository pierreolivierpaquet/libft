/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstadd_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:07:00 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 21:51:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 
/// @param head 
/// @param new_node 
/// @returns Pointer to the newly added node.
/// @note	new_node passes throught the function if it needs to
///			be freed immediately, in the case of a NULL head.
t_dbl_list	*ft_dbl_lstadd_back(t_dbl_list **head, t_dbl_list *new_node)
{
	t_dbl_list *iterator;

	iterator = NULL;
	if (head == NULL || new_node == NULL)
		return (new_node) ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		iterator = ft_dbl_lstlast(*head);
		iterator->next = new_node;
		new_node->previous = iterator;
	}
	return (new_node) ;
}
