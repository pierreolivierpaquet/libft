/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:32:50 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 16:32:46 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, t_gc func)
{
	char	*j;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	j = (char *)ft_alloc(CALLOC, \
						ft_strlen(s1) + ft_strlen(s2) + 1, \
						sizeof(*j), \
						func);
	if (j == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		j[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		j[i++] = *s2;
		s2++;
	}
	j[i] = '\0';
	return (j);
}
