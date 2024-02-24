/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:33:55 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/23 20:00:20 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks within the list if the memory was tracked. If so, it is freed.
/// @param to_free 
/// @returns NULL if the memory was found and freed.
static void	*ft_tracker_free(void **to_free)
{
	t_dlist	*allocations;

	allocations = ft_alloc_tracker(NULL, 0, false);
	while (allocations != NULL)
	{
		if ((*to_free) == (void *)allocations->content)
			return (ft_safe_free(to_free, allocations->size, false));
		allocations = allocations->next;
	}
	return (*to_free);
}

void	*ft_safe_free(void **to_free, size_t size, bool track)
{
	if (to_free == NULL || *to_free == NULL)
		return (NULL);
	if (track == true)
	{
		if (ft_tracker_free(to_free) == NULL)
			return (NULL);
	}
	if (size > 0)
		ft_bzero((*to_free), size);
	free(*to_free);
	*to_free = NULL;
	return (NULL);
}
