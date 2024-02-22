/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:45:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 20:50:29 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list	*ft_dbl_lstlast(t_dbl_list *here)
{
	t_dbl_list	*iterator;
	
	iterator = here;
	if (here == NULL)
		return (NULL);
	while (iterator->next != NULL)
		iterator = iterator->next;
	return (iterator);
}
