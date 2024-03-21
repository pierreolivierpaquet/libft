/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:23:18 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/21 00:52:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	t_dlist *test;
	char *one;
	char *two;
	char *three;
	char *four;

	one = ft_strdup("1");
	printf("%p\n", one);
	two = ft_strdup("22");
	three = ft_strdup("333");
	four = ft_strdup("4444");
	test = NULL;

	ft_dlstadd_back( &test, ft_dlstnew(one, ft_strlen(one), ft_alloc_tracker));
	ft_dlstadd_back(&test, ft_dlstnew(two, ft_strlen(two), ft_alloc_tracker));
	ft_dlstadd_back(&test, ft_dlstnew(three, ft_strlen(three), ft_alloc_tracker));
	ft_dlstadd_front(&test, ft_dlstnew(four, ft_strlen(four), ft_alloc_tracker));

	ft_alloc_tracker_destroy();
	return (0);
}