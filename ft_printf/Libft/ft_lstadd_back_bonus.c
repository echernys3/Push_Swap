/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:36:31 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:42:49 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*currentlst;

	currentlst = *lst;
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		while (currentlst -> next != NULL)
			currentlst = currentlst -> next;
		currentlst->next = new;
	}
}
