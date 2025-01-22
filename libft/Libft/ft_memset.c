/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:04 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:37:04 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int x, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
		dest[i++] = (unsigned char)x;
	return (s);
}
// #include <stdio.h>
// int main() 
// { 
//     char str[50] = "GeeksForGeeks is for programming geeks."; 
//     printf("\nBefore memset(): %s\n", str);
// 
// 	ft_memset(str + 13, '.', 8*sizeof(char)); 
// 
//     printf("After memset():  %s", str); 
//     return 0; 
// } 