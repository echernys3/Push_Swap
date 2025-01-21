/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:49 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:48:01 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	j = 0;
	while (j < len && big[j + i])
	{
		if (little[0] == big[j])
		{
			while ((j + i) < len && little[i] == big [j + i] && little [i])
				i++;
			if (!(little[i]))
				return ((char *)(big + j));
		}
		i = 0;
		j++;
	}
	return (NULL);
}

// int main()
// {
//     const char *big = "Hello, world!";
//     const char *little1 = "world";
//     const char *little2 = "test";
//     const char *little3 = ""; // Test with empty string
//     size_t len = 13; // Length of `big`
// 
//     // Test case: normal match
//     char *result1 = ft_strnstr(big, little1, len);
//     if (result1) {
//         printf("Found '%s' in '%s': %s\n", little1, big, result1);
//     } else {
//         printf("'%s' not found in '%s'\n", little1, big);
//     }
// 
//     // Test case: no match
//     char *result2 = ft_strnstr(big, little2, len);
//     if (result2) {
//         printf("Found '%s' in '%s': %s\n", little2, big, result2);
//     } else {
//         printf("'%s' not found in '%s'\n", little2, big);
//     }
// 
//     // Test case: empty little
//     char *result3 = ft_strnstr(big, little3, len);
//     if (result3) {
//         printf("Found empty string in '%s': %s\n", big, result3);
//     } else {
//         printf("Empty string not found in '%s'\n", big);
//     }
// 
//     // Test case: boundary condition
//     char *result4 = ft_strnstr(big, little1, 5); 
//		// Should not find "world" within the first 5 characters
//     if (result4) {
//         printf("Found '%s' in '%s': %s\n", little1, big, result4);
//     } else {
//         printf("'%s' not found in first 5 
//characters of '%s'\n", little1, big);
//     }
// }