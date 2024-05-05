/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:33:55 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 15:45:50 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief	Checks, within the list, if the memory was collected.
///			If so, it is freed.
/// @param to_free Pointer to be freed.
/// @returns NULL if the memory was "found and freed".
static void	*ft_gc_free(void **to_free)
{
	t_dlist	*allocations;

	allocations = ft_gc(NULL, 0);
	while (allocations != NULL)
	{
		if ((*to_free) == (void *)allocations->content)
		{
			ft_free(&allocations->content, allocations->size, false);
			allocations->size = 0;
			return (allocations->content);
		}
		allocations = allocations->next;
	}
	return (*to_free);
}

/// @brief Safely frees memory block, handling the garbage collecting process.
/// @param to_free Address of the pointer to be freed.
/// @param size Size, in bytes.
/// @param track	Wether the pointer needs to be processed in the
///					garbage collector or not.
void	*ft_free(void **to_free, size_t size, bool track)
{
	if (to_free == NULL || *to_free == NULL)
		return (NULL);
	if (track == true)
	{
		if (ft_gc_free(to_free) == NULL)
			return (NULL);
	}
	if (size > 0)
		ft_bzero((*to_free), size);
	free(*to_free);
	*to_free = NULL;
	return (NULL);
}
