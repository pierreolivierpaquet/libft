/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:31:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/04 20:28:39 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void *content, size_t size, gc func)
{
	t_dlist	*new;

	new = NULL;
	new = ft_alloc(CALLOC, 1, sizeof(*new), func);
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->size = size;
	return (new);
}

