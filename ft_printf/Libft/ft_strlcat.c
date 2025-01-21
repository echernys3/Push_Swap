/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:32 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:48:50 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (size <= i)
		return (ft_strlen(src) + size);
	while (src[j] && ((i + j) < (size - 1)))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}
/*
int main()
{
    char dst1[20] = "Hello, ";
    const char *src1 = "World!";
    size_t size1 = 20;

    char dst2[10] = "Hi, ";
    const char *src2 = "there!";
    size_t size2 = 9;

    char dst3[15] = "Short";
    const char *src3 = "Text";
    size_t size3 = 5;

    // Test case 1: Regular concatenation
    printf("Before: '%s', src: '%s', size: %zu\n", dst1, src1, size1);
    size_t result1 = ft_strlcat(dst1, src1, size1);
    printf("After: '%s', Result: %zu\n\n", dst1, result1);

    // Test case 2: Size too small
    printf("Before: '%s', src: '%s', size: %zu\n", dst2, src2, size2);
    size_t result2 = ft_strlcat(dst2, src2, size2);
    printf("After: '%s', Result: %zu\n\n", dst2, result2);

    // Test case 3: Exact size fit
    printf("Before: '%s', src: '%s', size: %zu\n", dst3, src3, size3);
    size_t result3 = ft_strlcat(dst3, src3, size3);
    printf("After: '%s', Result: %zu\n\n", dst3, result3);
}*/