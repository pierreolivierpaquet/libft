/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:31:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 21:16:19 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew( void *content)
{
	t_dlist	*new;

	new = NULL;
	new = ft_alloc(CALLOC, 1, sizeof(t_dlist), ft_alloc_tracker);
	if (new == NULL)
		return (NULL);
	new->content = content;
	return (new);
}

