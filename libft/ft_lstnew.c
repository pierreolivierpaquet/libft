/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:09:36 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 16:16:35 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, t_gc func)
{
	t_list	*head;

	head = (t_list *)ft_alloc(CALLOC, 1, sizeof(*head), func);
	if (!head)
		return (NULL);
	(*head).content = content;
	head->next = NULL;
	return (head);
}
