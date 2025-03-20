/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:11:17 by echernys          #+#    #+#             */
/*   Updated: 2025/03/17 16:12:28 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ps_atoi_no_split(const char *str, int *nums)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_with_error(nums, NULL, NULL);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > INT_MAX)
		exit_with_error(nums, NULL, NULL);
	return ((int)(res * sign));
}

int	*int_array_no_split(char **str, int size)
{
	int	*nums;
	int	i;

	nums = ft_calloc(size, sizeof(int));
	if (!nums)
		exit(1);
	i = 0;
	while (i < size)
	{
		if (str[i] == NULL || str[i][0] == '\0')
			exit_with_error(nums, NULL, NULL);
		nums[i] = ps_atoi_no_split(str[i], nums);
		i++;
	}
	return (nums);
}

static int	ps_atoi(const char *str, int *nums, char **error, int size)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_on_split(nums, error, size);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > INT_MAX)
		exit_with_error(nums, NULL, NULL);
	return ((int)(res * sign));
}

int	*int_array(char **str, int size)
{
	int	*nums;
	int	i;

	nums = ft_calloc(size, sizeof(int));
	if (!nums)
		exit(1);
	i = 0;
	while (i < size)
	{
		if (str[i] == NULL || str[i][0] == '\0')
			exit_with_error (nums, NULL, NULL);
		nums[i] = ps_atoi(str[i], nums, str, size);
		i++;
	}
	return (nums);
}

void	check_doubles(int *nums, int size)
{
	int	current;
	int	runner;

	current = 0;
	while (current < size - 1)
	{
		runner = current + 1;
		while (runner < size)
		{
			if (nums[current] == nums [runner])
				exit_with_error(nums, NULL, NULL);
			runner++;
		}
		current++;
	}
}
