/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:15:03 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/07 15:44:02 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int start, int stop)
{
	char	*trg;
	int		i;
	int		count;

	count = 0;
	while (src[count])
	{
		count++;
	}
	i = 0;
	trg = (char *)malloc(count * sizeof(char));
	while (src[start] && start < stop)
		trg[i++] = src[start++];
	trg[i] = '\0';
	return (trg);
}

int	is_seperator(char s, char c)
{
	if (s == c)
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
	if (str[i] == '\0' && words > 0)
		words++;
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
	while (j < words)
	{
		while (is_seperator(s[i], c))
			i++;
		start = i;
		while (!(is_seperator(s[i], c)))
			i++;
		tab[j] = ft_strndup((char *)s, start, i);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
