/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:57:33 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 21:02:18 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dbl_lstsize(t_dbl_list *from)
{
	t_dbl_list	*iterator;
	size_t		size;

	iterator = from;
	size = 0;
	if (from == NULL)
		return (size);
	while (size++ && iterator->next != NULL)
		iterator = iterator->next;
	return (size);
}
