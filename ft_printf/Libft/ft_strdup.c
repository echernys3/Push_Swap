/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:29:39 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:50:31 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	s_len;
	size_t	count;

	count = 0;
	s_len = ft_strlen(s);
	dup = malloc(sizeof(char) * (s_len + 1));
	if (!(dup))
		return (NULL);
	while (s[count])
	{
		dup[count] = s[count];
		count++;
	}
	dup[count] = '\0';
	return (dup);
}
