/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:36:29 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 17:15:36 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	numlen(long num)
{
	size_t	str_len;

	str_len = 0;
	if (num < 0)
	{
		num = -num;
		str_len++;
	}
	while (num > 0)
	{
		num /= 10;
		str_len++;
	}
	return (str_len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	str_len;
	long	num;

	num = n;
	if (num == 0)
		return (ft_strdup("0"));
	str_len = numlen(num);
	str = malloc(sizeof(char) * (str_len + 1));
	if (!(str))
		return (NULL);
	str[str_len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[str_len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
// 
// #include <stdio.h>
// 
// int main() {
//     int numbers[] = {0, 42, -42, 2147483647, -2147483648};
//     size_t count = sizeof(numbers) / sizeof(numbers[0]);
// 
//     for (size_t i = 0; i < count; i++) {
//         char *result = ft_itoa(numbers[i]);
//         if (result) {
//             printf("ft_itoa(%d) = %s\n", numbers[i], result);
//             free(result); // Don't forget to free the allocated memory
//         } else {
//             printf("ft_itoa(%d) failed to allocate memory.\n", numbers[i]);
//         }
//     }
// }