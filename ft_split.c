/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:58:38 by rarayano          #+#    #+#             */
/*   Updated: 2026/04/17 02:14:17 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in;
	int		i;

	count = 0;
	in = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in == 0)
		{
			in = 1;
			count++;
		}
		else if (s[i] == c)
			in = 0;
		i++;
	}
	return (count);
}

static char	*dup_word(char const *start, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_all(char **arr, size_t i)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free (arr);
	return (NULL);
}

static int	fill_split(char **arr, char const *s, char c, size_t wc)
{
	size_t		i;
	size_t		j;
	size_t		start;

	i = 0;
	j = 0;
	while (i < wc)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] != '\0' && s[j] != c)
			j++;
		arr[i] = dup_word(s + start, (j - start));
		if (!arr[i])
		{
			free_all(arr, i);
			return (0);
		}
		i++;
	}
	arr[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = count_words(s, c);
	arr = malloc((wc + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_split(arr, s, c, wc))
		return (NULL);
	return (arr);
}
