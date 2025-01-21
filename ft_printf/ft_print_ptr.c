/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:49:10 by echernys          #+#    #+#             */
/*   Updated: 2024/10/10 13:08:43 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(const void *c, int print_len)
{
	unsigned int	**ptr;
	

	ptr = (unsigned int **)&c;
	print_len += ft_print_hex(**ptr, 'x');
	return (print_len);
}