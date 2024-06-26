/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:00:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 16:29:26 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief	Function used by the memory allocating function, to keep a trace of
///			the allocated block of memory.
/// @param newly_allocated If NULL, the function acts like a getter.
/// @returns A pointer to the first node of the garbage collector linked list.
t_dlist	*ft_gc(void *newly_allocated, size_t size)
{
	static t_dlist	*t_gc;

	if (t_gc == NULL)
	{
		t_gc = ft_alloc(CALLOC, 1, sizeof(*t_gc), NULL);
		if (t_gc != NULL)
		{
			t_gc->content = newly_allocated;
			t_gc->size = size;
		}
		return (t_gc);
	}
	if (t_gc->content == NULL && newly_allocated != NULL)
	{
		t_gc->content = newly_allocated;
		t_gc->size = size;
	}
	else if (newly_allocated != NULL)
		ft_dlstadd_back(&t_gc, ft_dlstnew(newly_allocated, size, NULL));
	return (t_gc);
}

///	@brief Suppresses all the allocated memory by the garbage collector.
void	*ft_gc_destroy( void )
{
	t_dlist	*retrieve_gc;
	t_dlist	*to_free;

	retrieve_gc = NULL;
	retrieve_gc = ft_gc(NULL, 0);
	while (retrieve_gc != NULL)
	{
		to_free = retrieve_gc;
		retrieve_gc = retrieve_gc->next;
		ft_free(&(to_free->content), to_free->size, false);
		ft_free((void *)&to_free, sizeof(*to_free), false);
	}
	return (NULL);
}

/// @brief Customized memory allocation function.
/// @param type Type of memory allocation, wether it's CALLOC or MALLOC.
/// @param count Total amount of contiguous block of memory allocated.
/// @param size Size, in bytes (ex: memory block from sizeof()).
/// @param func Function pointer to the garbage collector. If NULL, memory
///				allocation will not be tracked.
/// @returns The newly allocated pointer.
void	*ft_alloc(t_alloc_type type, size_t count, size_t size, t_gc func)
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
			new_pointer = (void *)ft_calloc(count, size);
		else
			new_pointer = (void *)malloc(count * size);
	}
	if (new_pointer != NULL && func != NULL)
		func(new_pointer, count * size);
	return (new_pointer);
}
