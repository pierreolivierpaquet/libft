/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:57:18 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 18:55:30 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstadd_front(t_dlist **head, t_dlist *new_node)
{
	t_dlist *iterator;
	
	iterator = NULL;
	if (head == NULL || new_node == NULL)
		return (new_node);
	if (*head == NULL)
		*head = new_node;
	else
	{
		iterator = ft_dlstfirst(*head);
		iterator->previous = new_node;
		new_node->next = iterator;
		*head = new_node;
	}
	return (new_node);
}
