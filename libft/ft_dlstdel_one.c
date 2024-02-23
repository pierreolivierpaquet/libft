/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:30:11 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 19:47:56 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dlstdel_one(t_dlist **delete, ft_free func)
{
	if (delete == NULL || *delete == NULL)
		return(NULL);
	if (func != NULL && (*delete)->content != NULL)
		func((*delete)->content);
	ft_bzero(*delete, sizeof(**delete));
	free(*delete);
	(*delete) = NULL;
	return (NULL);
}
