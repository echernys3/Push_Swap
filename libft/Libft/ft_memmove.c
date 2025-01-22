/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:01 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:37:02 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

static char	*ft_movedat(unsigned char *to, unsigned const char *from, size_t n)
{
	size_t				i;

	i = 0;
	if (to < from && n != 0)
	{
		while (i < n)
		{
			to[i] = from[i];
			i++;
		}
	}
	else if (to > from && n != 0)
	{
		i = n;
		while (i > 0)
		{
			to[i - 1] = from[i - 1];
			i--;
		}
	}
	return ((char *)to);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*to;
	const unsigned char	*from;

	if (!dest && !src)
		return (NULL);
	to = (unsigned char *)dest;
	from = (const unsigned char *)src;
	ft_movedat(to, from, n);
	return (dest);
}
// 
// int main() 
// {
// 	char src[] = "mitochondria are the powerhouses of cells";
// 	char dest[213];
// 
// 	printf("\nBefore:   %s\n", src);
// 
// 	ft_memmove(dest, src, 42*sizeof(char)); 
// 
// 	printf("After:    %s", dest); 
// 	return 0;
// }