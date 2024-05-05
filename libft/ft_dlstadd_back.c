/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:07:00 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 16:12:49 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 
/// @param head 
/// @param new_node 
/// @returns Pointer to the newly added node.
/// @note	new_node passes throught the function if it needs to
///			be freed immediately, in the case of a NULL head.
t_dlist	*ft_dlstadd_back(t_dlist **head, t_dlist *new_node)
{
	t_dlist	*iterator;

	iterator = NULL;
	if (head == NULL || new_node == NULL)
		return (new_node);
	if (*head == NULL)
		*head = new_node;
	else
	{
		iterator = ft_dlstlast(*head);
		iterator->next = new_node;
		new_node->previous = iterator;
	}
	return (new_node);
}
