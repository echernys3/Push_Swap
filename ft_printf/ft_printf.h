/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:56:57 by echernys          #+#    #+#             */
/*   Updated: 2024/10/10 13:07:23 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	FT_PRINTF_H
# define	FT_PRINTF_H

# include	<stdlib.h>
# include	<stdarg.h>

int	ft_numlen(unsigned int n);
int	ft_putchar(char c);

int	ft_printf(const char *str, va_list arg);
int	ft_print_ptr(const void *c, int print_len);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, const char format);

#endif