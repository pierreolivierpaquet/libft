/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:23:18 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 21:57:17 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	t_dlist *test;
	void *one;
	void *two;
	void *three;
	void *four;
	
	one = malloc(1);
	two = malloc(1);
	three = malloc(1);
	four = malloc(1);
	test = NULL;
	
	ft_alloc_tracker(NULL);
	ft_dlstadd_back( &test, ft_dlstnew(one));
	ft_dlstadd_back(&test, ft_dlstnew(two));
	ft_dlstadd_back(&test, ft_dlstnew(three));
	ft_dlstadd_front(&test, ft_dlstnew(four));

	ft_dlst_clear(&test, free);

	while (test != NULL)
	{
		printf("CONTENT: %s\n", (char *)test->content);
		test = test->next;
	}
	return (0);
}