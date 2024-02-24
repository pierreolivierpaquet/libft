/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:00:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/23 22:15:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief	Function used by the memory allocating function, to keep a trace of
///			the allocated memory.
/// @param newly_allocated If NULL, the function acts like a getter.
/// @returns A pointer to the first node of the memory tracker linked list.
t_dlist *ft_alloc_tracker(void *newly_allocated, size_t size, bool destroy)
{
	static t_dlist *tracker;

	if (tracker == NULL)
	{
		tracker = ft_alloc(CALLOC, 1, sizeof(*tracker), NULL);
		
		if (tracker != NULL)
		{
			tracker->content = newly_allocated;
			tracker->size = size;
		}
		return (tracker);
	}
	if (newly_allocated == NULL && destroy == true)
		return (ft_dlst_clear(&tracker, ft_safe_free), NULL);
	if (tracker->content == NULL && newly_allocated != NULL)
		tracker->content = newly_allocated;
	else if (newly_allocated != NULL)
		ft_dlstadd_back(&tracker, ft_dlstnew(newly_allocated, size, NULL));
	return (tracker);
}

/// @brief Custom allocation function.
/// @param type Type of memory allocation, wether it's calloc or malloc.
/// @param count Total amount of contiguous block of memory allocated.
/// @param size Size in bytes (ex: memory block from sizeof())
/// @param func Function pointer to memory allocation tracker. If NULL, memory
///				allocation will not be tracked.
/// @returns The newly allocated pointer.
void	*ft_alloc(e_alloc_type type, size_t count, size_t size, mem_track func)
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
	if (ptr != NULL && func != NULL)
		func(ptr, count * size, false);
	return (ptr);
}
