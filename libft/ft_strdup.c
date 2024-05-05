/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:14:57 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/04 20:40:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1, gc func)
{
	char	*copie;
	size_t	l;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1) + 1;

	copie = (char *)ft_alloc(CALLOC, l, sizeof(*copie), func);
	if (copie == NULL)
		return (NULL);
	else
		ft_memcpy(copie, s1, l);
	return (copie);
}
