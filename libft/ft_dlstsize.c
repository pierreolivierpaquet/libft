/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:57:33 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 15:48:27 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlstsize(t_dlist *from)
{
	t_dlist	*iterator;
	size_t	size;

	iterator = from;
	size = 0;
	if (from == NULL)
		return (size);
	while (size++ && iterator->next != NULL)
		iterator = iterator->next;
	return (size);
}
