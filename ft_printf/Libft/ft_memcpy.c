/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:36:59 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:37:00 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*to;
	const unsigned char	*from;

	i = 0;
	to = (unsigned char *)dest;
	from = (const unsigned char *)src;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dest);
}
// int main() 
// { 
//     char src[] = "mitochondria are the powerhouses of cells"; 
//     char dest[42];
// 
// 	printf("\nBefore memcpy(): %s\n", src);
// 
//     ft_memcpy(dest, src, 42*sizeof(char)); 
// 	// dest [20] = '\0';
// 
//     printf("After memcpy():  %s", dest); 
//     return 0; 
// }