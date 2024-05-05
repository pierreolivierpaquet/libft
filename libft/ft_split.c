/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:33:30 by ppaquet           #+#    #+#             */
/*   Updated: 2024/05/04 22:13:02 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_count(const char *str, const char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
			while (str[i] && str[i] == c)
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (count);
}

static int	letter_count(const char *str, char c)
{
	int	i;
	int	l_c;

	i = 0;
	l_c = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		i++;
		l_c++;
	}
	return (i);
}

static char	**free_all(char **str, int n)
{
	int	i;

	i = (n - 1);
	while (i >= 0)
	{
		// free(str[i]);
		ft_safe_free((void **)&str[i], ft_strlen(str[i]), true);
		i--;
	}
	// free(str);
	ft_safe_free((void **)&str, n, true);
	return (NULL);
}

static char	**head_splitter(char **tab, const char *s, const char c, gc func)
{
	int			i;
	int			j;
	size_t		l_c;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			l_c = letter_count(&s[i], c);
			tab[j] = (char *)ft_alloc(CALLOC, l_c + 1, sizeof(char), func);
			// TEST
			if (j == 2) {tab[j] = NULL; }
			// TEST END
			if (!tab[j])
				return (free_all(tab, j));
			ft_strlcpy(tab[j], &s[i], l_c + 1);
			j++;
			i += letter_count(&s[i], c);
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c, gc func)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_alloc(CALLOC, word_count(s, c) + 1, sizeof(*tab), func);
	if (!tab)
		return (NULL);
	tab = head_splitter(tab, s, c, func);
	return (tab);
}
