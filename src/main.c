/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:01:23 by echernys          #+#    #+#             */
/*   Updated: 2025/03/17 16:10:08 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**temp;
	int		*nums;
	int		size;
	t_stack	*stack_a;

	if (argc < 2)
		exit(1);
	size = argc - 1;
	temp = NULL;
	if (argc == 2)
	{
		size = ps_count_size(argv[1], ' ');
		temp = ps_split_nums(argv[1], ' ', size);
		nums = int_array(temp, size);
		split_freer(temp, size);
	}
	else
		nums = int_array_no_split(&argv[1], size);
	check_doubles(nums, size);
	stack_a = create_lst(nums, size);
	ps_get_index(&stack_a, size, nums);
	push_swap(&stack_a, size);
	if (nums)
		free(nums);
	return (0);
}
