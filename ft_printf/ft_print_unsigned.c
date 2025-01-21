/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:49:12 by echernys          #+#    #+#             */
/*   Updated: 2024/10/10 13:09:39 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*miniitoa(unsigned int n)
{
	char	*str;
	int	n_len;

	n_len = ft_numlen(n);
	str = malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (0);
	str[n_len--] = '\0';
	while (n_len >= 0 && n)
	{
		str[n_len] = n % 10 + '0';
		n /= 10;
		n_len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_len;
	char	*str;

	print_len = 0;
	if (n == 0)
		print_len += ft_putchar('0');
	else 
	{
		str = miniitoa(n);
		while(str[print_len])
			ft_putchar(str[print_len++]);
		print_len--;
		free(str);
	}
	return (print_len);
}
