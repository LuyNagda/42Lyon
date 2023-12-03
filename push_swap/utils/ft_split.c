/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:15:03 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/02 23:21:21 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnndup(char *src, int start, int stop)
{
	char	*trg;
	int		i;

	i = 0;
	trg = (char *)malloc((stop - start + 1) * sizeof(char));
	if (!trg)
		return (NULL);
	while (src[start] && start < stop)
		trg[i++] = src[start++];
	trg[i] = '\0';
	return (trg);
}

int	is_seperator(char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	return (0);
}

int	count_words(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((is_seperator(str[i + 1], c) == 1)
			&& (is_seperator(str[i], c) == 0))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	int		words;
	char	**tab;

	i = 0;
	j = 0;
	start = 0;
	words = count_words(s, c);
	tab = (char **)malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (j < words)
	{
		while (is_seperator(s[i], c))
			i++;
		start = i;
		while (!(is_seperator(s[i], c)))
			i++;
		tab[j++] = ft_strnndup((char *)s, start, i);
	}
	tab[j] = 0;
	return (tab);
}
