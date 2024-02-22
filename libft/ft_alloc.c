/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:00:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 19:26:11 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Custom allocation function.
/// @param type Type of memory allocation, wether it's calloc or malloc.
/// @param count Total amount of contiguous block of memory allocated.
/// @param size Size in bytes (ex: memory block from sizeof())
/// @param store Address to store the newly allocated pointer.
/// @returns The newly allocated pointer.
void	*ft_alloc(e_alloc_type type, size_t count, size_t size, void **store)
{
	void	*ptr = NULL;
	int		tries;

	if (count == 0 || size == 0)
		return (NULL);
	tries = -1;
	while (ptr == NULL && ++tries < TRY_ALLOC)
	{
		if (type == CALLOC)
			ptr = ft_calloc(count, size);
		else
			ptr = (void *)malloc(count * size);	
	}
	if (ptr != NULL && store != NULL)
		*store = ptr;
	return (ptr);
}
