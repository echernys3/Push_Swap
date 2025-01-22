/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:18 by echernys          #+#    #+#             */
/*   Updated: 2024/10/08 11:53:12 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freer(char **tab, int wordscount)
{
	while (wordscount > 0)
		free(tab[--wordscount]);
	free(tab);
}

static char	**spcalloc(const char *s, char c)
{
	int		i;
	int		wordscount;
	char	**tab;

	i = 0;
	wordscount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			wordscount++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab = malloc(sizeof(char *) * (wordscount + 1));
	if (!tab)
		return (NULL);
	tab[wordscount] = NULL;
	return (tab);
}

static int	wordalloc(char **tab, int wordscount, int wrd_len)
{
	tab[wordscount] = malloc(sizeof(char) * (wrd_len + 1));
	if (!(tab[wordscount]))
	{
		freer(tab, wordscount);
		return (0);
	}
	return (1);
}

static int	wrdlen(char const *s, char c, int i, int wrd_len)
{
	while (s[i + wrd_len] && s[i + wrd_len] != c)
		wrd_len++;
	return (wrd_len);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wordscount;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	wordscount = 0;
	tab = spcalloc(s, c);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			if (wordalloc(tab, wordscount, wrdlen(s, c, i, 0)) == 0)
				return (NULL);
			ft_strlcpy(tab[wordscount], &s[i], wrdlen(s, c, i, 0) + 1);
			wordscount++;
			i += wrdlen(s, c, i, 0);
		}
	}
	return (tab);
}
