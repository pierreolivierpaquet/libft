/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:51:15 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 18:55:54 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstfirst(t_dlist *here)
{
	t_dlist	*iterator;
	
	iterator = here;
	if (here == NULL)
		return (NULL);
	while (iterator->previous != NULL)
		iterator = iterator->previous;
	return (iterator);
}
