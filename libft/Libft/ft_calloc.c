/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:36:05 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 15:12:34 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!(ptr))
		return (NULL);
	ft_memset(ptr, '\0', (nmemb * size));
	return (ptr);
}
// 
// int main() {
//     // Test 1: Normal allocation
//     size_t num_elements = 5;
//     size_t element_size = sizeof(int);
//     int *arr = (int *)ft_calloc(num_elements, element_size);
// 
//     if (arr) {
//         printf("Test 1: Allocated %zu 
// 		elements of size %zu\n", num_elements, element_size);
//         for (size_t i = 0; i < num_elements; i++) {
//             printf("arr[%zu] = %d\n", i, 
//arr[i]); // Should all be initialized to 0
//         }
//         free(arr);
//     } else {
//         printf("Test 1: Memory allocation failed\n");
//     }
//
//     // Test 2: Zero allocation (should return 
// 	a valid pointer to zero bytes)
// 	int *zero_arr = (int *)ft_calloc(0, sizeof(int));
// 	if (zero_arr == NULL) {
// 		printf("Test 2: Correctly returned NULL for zero allocation\n");
// 	} else {
// 		printf("Test 2: Successfully 
// 		allocated zero bytes (valid pointer)\n");
// 		free(zero_arr); // Freeing the 
// 		pointer, even though it points to zero bytes
// 	}
// 
//     // Test 3: Check for overflow
//     size_t overflow_elements = SIZE_MAX; 
// Using SIZE_MAX to trigger overflow
//     int *overflow_arr = (int *)ft_calloc(overflow_elements, sizeof(int));
//     if (overflow_arr == NULL) {
//         printf("Test 3: Correctly handled overflow allocation\n");
//     } else {
//         printf("Test 3: Unexpected successful allocation on overflow\n");
//         free(overflow_arr);
//     }
// }