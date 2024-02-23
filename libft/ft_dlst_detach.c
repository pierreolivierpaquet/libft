/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_detach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:49:42 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 22:03:11 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dlst_detach(t_dlist **head, t_dlist *detach, ft_free func)
{
	if(head == NULL || *head == NULL || detach == NULL)
		return (NULL);
	if (*head == detach)
	{
		(*head) = (*head)->next;
		if (*head != NULL)
			(*head)->previous = NULL;
	}
	else
	{
		(detach)->previous->next = (detach)->next;
		if ((detach)->next != NULL)
			(detach)->next->previous = (detach)->previous;
		else
			(detach)->previous->next = NULL;
	}
	if (func != NULL)
		ft_dlstdel_one(&detach, func);
	return (*head);
}
