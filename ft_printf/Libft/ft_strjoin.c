/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:29 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 17:27:15 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	tot_len;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char) * (tot_len + 1));
	if (!(newstr))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	newstr[ft_strlen(s1) + i] = '\0';
	return (newstr);
}
// ft_strlcat(newstr + i, s2, ft_strlen(s2) + 1); ou meme ft_memcpy
