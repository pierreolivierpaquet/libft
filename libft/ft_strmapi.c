/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:34:02 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/04 22:31:45 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char), gc func)
{
	char	*buf;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	buf = (char *)ft_alloc(CALLOC, len + 1, sizeof(*buf), func);
	if (buf == NULL)
		return (NULL);
	while (i < len)
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[len] = '\0';
	return (buf);
}
