/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:30:11 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 16:03:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dlstdel_one(t_dlist **delete, t_free func)
{
	if (delete == NULL || *delete == NULL)
		return (NULL);
	if (func != NULL && (*delete)->content != NULL)
		func(&(*delete)->content, (*delete)->size, true);
	ft_free((void **)delete, sizeof(delete), true);
	return (NULL);
}
