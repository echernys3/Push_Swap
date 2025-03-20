/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:08:19 by echernys          #+#    #+#             */
/*   Updated: 2025/03/17 14:28:33 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	bubble_sort_stack(t_stack **tab, int size)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i]->num > tab[j]->num)
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	update_index(t_stack **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i]->index = i + 1;
		i++;
	}
}

void	ps_get_index(t_stack **head, int size, int *nums)
{
	t_stack	**tab;
	t_stack	*temp;
	int		i;

	if (!head || !*head)
		exit_with_error(nums, *head, NULL);
	tab = ft_calloc(size, sizeof(t_stack));
	if (!tab)
		exit_with_error(nums, *head, NULL);
	temp = *head;
	i = 0;
	while (temp && i < size)
	{
		tab[i] = temp;
		temp = temp->next;
		i++;
	}
	bubble_sort_stack(tab, size);
	update_index(tab, size);
	free(tab);
}
