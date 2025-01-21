/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:47 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:51:55 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <string.h>
//
// int main() {
// 	const char *str1 = "test\200";
// 	const char *str2 = "test\0";
// 	int n = 15; // n is greater than both strings' lengths
//
// 	int result = ft_strncmp(str1, str2, n);
// 	int	result2 = strncmp(str1, str2, n);
//	
// 	printf("'%d'\n", result);
// 	if (result < 0) {
// 		printf("'%s' is less than '%s'\n", str1, str2);
// 	} else if (result > 0) {
// 		printf("'%s' is greater than '%s'\n", str1, str2);
// 	} else {
// 		printf("'%s' is equal to '%s'\n", str1, str2);
// 	}
// 	printf("'%d'\n", result2);
// 	if (result2 < 0) {
// 		printf("'%s' is less than '%s'\n", str1, str2);
// 	} else if (result2 > 0) {
// 		printf("'%s' is greater than '%s'\n", str1, str2);
// 	} else {
// 		printf("'%s' is equal to '%s'\n", str1, str2);
// 	}
// }
