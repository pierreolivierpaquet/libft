/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:14:57 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 16:16:35 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1, t_gc func)
{
	char	*copy;
	size_t	l;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1) + 1;
	copy = (char *)ft_alloc(CALLOC, l, sizeof(*copy), func);
	if (copy == NULL)
		return (NULL);
	else
		ft_memcpy(copy, s1, l);
	return (copy);
}
