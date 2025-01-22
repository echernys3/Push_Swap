/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:54 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 17:28:17 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	startpos(char const *s1, char const *set, size_t s1_len)
{
	size_t	i;
	size_t	setindex;

	i = 0;
	while (i < s1_len)
	{
		setindex = 0;
		while (set[setindex])
		{
			if (s1[i] == set[setindex])
				break ;
			setindex++;
		}
		if (set[setindex] != s1[i])
			break ;
		i++;
	}
	return (i);
}

static size_t	endpos(char const *s1, char const *set, int end)
{
	size_t	setindex;

	while (end >= 0)
	{
		setindex = 0;
		while (set[setindex])
		{
			if (s1[end] == set[setindex])
				break ;
			setindex++;
		}
		if (set[setindex] != s1[end])
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = startpos(s1, set, s1_len);
	end = endpos(s1, set, s1_len);
	return (ft_substr(s1, start, end - start + 1));
}
