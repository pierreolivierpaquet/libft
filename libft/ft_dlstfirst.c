/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:51:15 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/04 20:32:10 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstfirst(t_dlist *from)
{
	t_dlist	*iterator;

	iterator = from;
	if (from == NULL)
		return (NULL);
	while (iterator->previous != NULL)
		iterator = iterator->previous;
	return (iterator);
}
