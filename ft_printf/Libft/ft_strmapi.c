/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:37:45 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:51:32 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	str_len;
	unsigned int	index;

	if (!(s))
		return (NULL);
	str_len = ft_strlen(s);
	str = malloc(sizeof(char) * (str_len + 1));
	if (!(str))
		return (NULL);
	index = 0;
	while (s[index])
	{
		str[index] = (*f)(index, s[index]);
		index++;
	}
	str[str_len] = '\0';
	return (str);
}
