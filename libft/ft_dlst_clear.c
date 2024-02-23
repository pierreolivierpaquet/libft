/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:39:47 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 21:53:27 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_clear(t_dlist **head, ft_free func)
{
	if (head == NULL || *head == NULL)
		return;
	while (*head != NULL)
		ft_dlst_detach(head, *head, func);
	return ;
}
