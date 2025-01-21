/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:52 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 17:26:27 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr;
	unsigned char	normalized_c;

	normalized_c = (unsigned char)(c % 256);
	ptr = s + ft_strlen(s);
	if (normalized_c == '\0')
		return ((char *)ptr);
	while (ptr != s)
	{
		if (*(ptr - 1) == normalized_c)
			return ((char *)(ptr - 1));
		ptr--;
	}
	return (NULL);
}
// Tiens ça la francinette, MODULO 256 FOR THE WIN