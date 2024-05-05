/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:23:18 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/05 13:31:44 by ppaquet          ###   ########.fr       */
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

	one = ft_strdup("1", ft_gc);
	printf("%p\n", one);
	two = ft_strdup("22", ft_gc);
	three = ft_strdup("333", ft_gc);
	four = ft_strdup("4444", ft_gc);
	test = NULL;

	ft_dlstadd_back( &test, ft_dlstnew(one, ft_strlen(one), ft_gc));
	ft_dlstadd_back(&test, ft_dlstnew(two, ft_strlen(two), ft_gc));
	ft_dlstadd_back(&test, ft_dlstnew(three, ft_strlen(three), ft_gc));
	ft_dlstadd_front(&test, ft_dlstnew(four, ft_strlen(four), ft_gc));

	ft_gc_destroy();
	return (0);
}