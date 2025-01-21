/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:20 by echernys          #+#    #+#             */
/*   Updated: 2024/10/08 11:52:42 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	int				i;
	unsigned char	normalized_c;

	normalized_c = (unsigned char)(c % 256);
	ptr = (char *)s;
	if (normalized_c == '\0')
		return (ptr + ft_strlen(s));
	i = 0;
	while (s[i] != normalized_c && s[i])
		i++;
	if (i >= ft_strlen(s))
		return (NULL);
	return (ptr + i);
}
