/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:12 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:37:13 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	if (num > 9)
	{
		ft_putnbr_fd((num / 10), fd);
		ft_putchar_fd((num % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((num % 10 + '0'), fd);
}
// 
// int	main()
// {
// 	int	n = 0;
// 	ft_putnbr_fd(n, 1);
// }