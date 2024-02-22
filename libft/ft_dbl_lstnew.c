/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:31:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 12:33:08 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list	*ft_dbl_lstnew( void *content)
{
	t_dbl_list	*new;

	new = NULL;
	
	if (ft_alloc(CALLOC, 1, sizeof(t_dbl_list), (void **)&new) == NULL)
		return (NULL);
	new->content = content;
	return (new);
}

int main(void)
{
	t_dbl_list *test;
	char string[25] = "This is a test";
	char string2[25] = "This is a second string!";
	char string3[25] = "Third string here...";
	char string4[25] = "NEW! Node at first!!!";
		
	test = NULL;
	// test = ft_dbl_lstnew((void *)string);
	
	ft_dbl_lstadd_back( &test, ft_dbl_lstnew((void *)string));
	
	ft_dbl_lstadd_back(&test, ft_dbl_lstnew((void *)string2));
	ft_dbl_lstadd_back(&test, ft_dbl_lstnew((void *)string3));
	ft_dbl_lstadd_front(&test, ft_dbl_lstnew((void *)string4));
	while (test != NULL)
	{
		printf("CONTENT: %s\n", (char *)test->content);
		test = test->next;
	}
	return (0);
}
