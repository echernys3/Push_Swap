/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:56:52 by echernys          #+#    #+#             */
/*   Updated: 2025/03/17 16:13:09 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_count_size(char *str, char c)
{
	int	size;
	int	i;

	if (str == NULL || str[0] == '\0')
		exit_with_error (NULL, NULL, NULL);
	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			size++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (size);
}

void	split_freer(char **tab, int size)
{
	while (size > 0)
		free(tab[--size]);
	free(tab);
}

static int	wrdlen(char const *str, char c, int i)
{
	int	wrd_len;

	wrd_len = 0;
	while (str[i + wrd_len] && str[i + wrd_len] != c)
		wrd_len++;
	return (wrd_len);
}

static void	alloc_element(char **nums, int wrdcount, int wrd_len, int size)
{
	nums[wrdcount] = ft_calloc(wrd_len + 1, sizeof(char));
	if (!nums)
	{
		split_freer(nums, size);
		exit_with_error (NULL, NULL, NULL);
	}
}

char	**ps_split_nums(char *str, char c, int size)
{
	char	**nums;
	int		i;
	int		wrdcount;

	nums = ft_calloc(size, sizeof(char *));
	if (!nums)
		exit_with_error(NULL, NULL, NULL);
	i = 0;
	wrdcount = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			alloc_element(nums, wrdcount, wrdlen(str, c, i), size);
			ft_strlcpy(nums[wrdcount], (str + i), wrdlen(str, c, i) + 1);
			wrdcount++;
			i += wrdlen(str, c, i);
		}
	}
	return (nums);
}
