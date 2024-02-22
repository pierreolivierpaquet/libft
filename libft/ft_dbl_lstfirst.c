/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:51:15 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 20:56:08 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list	*ft_dbl_lstfirst(t_dbl_list *here)
{
	t_dbl_list	*iterator;
	
	iterator = here;
	if (here == NULL)
		return (NULL);
	while (iterator->previous != NULL)
		iterator = iterator->previous;
	return (iterator);
}
