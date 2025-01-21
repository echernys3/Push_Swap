/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:36 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:42:39 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
// 
// int main() {
// 	char dst[20];
// 	const char *src = "Hello, World!";
// 
// 	size_t result = ft_strlcpy(dst, src, 0);
// 
// 	printf("Dest: '%s'\n", dst);
// 	printf("Source length: %zu\n", result);
// }
