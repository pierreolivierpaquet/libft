/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:00:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/21 00:52:09 by ppaquet          ###   ########.fr       */
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

void	*ft_alloc_tracker_destroy( void )
{
	t_dlist	*retrieve_tracker;
	t_dlist	*to_free;

	retrieve_tracker = ft_alloc_tracker(NULL, 0, 0);
	while (retrieve_tracker != NULL)
	{
		to_free = retrieve_tracker;
		retrieve_tracker = retrieve_tracker->next;
		ft_safe_free(&(to_free->content), to_free->size, false);
		ft_safe_free((void *)&to_free, sizeof(*to_free), false);
	}
	return (NULL);
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
	void	*new_pointer;
	int		tries;

	new_pointer = NULL;
	if (count == 0 || size == 0)
		return (NULL);
	tries = -1;
	while (new_pointer == NULL && ++tries < TRY_ALLOC)
	{
		if (type == CALLOC)
			new_pointer = ft_calloc(count, size);
		else
			new_pointer = (void *)malloc(count * size);	
	}
	if (new_pointer != NULL && func != NULL)
		func(new_pointer, count * size, false);
	return (new_pointer);
}
