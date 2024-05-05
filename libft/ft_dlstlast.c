/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:45:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/04 20:31:45 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstlast(t_dlist *from)
{
	t_dlist	*iterator;
	
	iterator = from;
	if (from == NULL)
		return (NULL);
	while (iterator->next != NULL)
		iterator = iterator->next;
	return (iterator);
}
