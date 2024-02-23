/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:45:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 18:56:06 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstlast(t_dlist *here)
{
	t_dlist	*iterator;
	
	iterator = here;
	if (here == NULL)
		return (NULL);
	while (iterator->next != NULL)
		iterator = iterator->next;
	return (iterator);
}
