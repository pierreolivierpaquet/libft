/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstadd_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:57:18 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 12:31:15 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list	*ft_dbl_lstadd_front(t_dbl_list **head, t_dbl_list *new_node)
{
	t_dbl_list *iterator;
	
	iterator = NULL;
	if (head == NULL || new_node == NULL)
		return (new_node);
	if (*head == NULL)
		*head = new_node;
	else
	{
		iterator = ft_dbl_lstfirst(*head);
		iterator->previous = new_node;
		new_node->next = iterator;
		*head = new_node;
	}
	return (new_node);
}
