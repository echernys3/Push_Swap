/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:36:46 by echernys          #+#    #+#             */
/*   Updated: 2024/10/07 12:36:46 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newhead;
	t_list	*newnode;

	if (!lst || !del || !f)
		return (NULL);
	newhead = NULL;
	while (lst)
	{
		newnode = ft_lstnew(f(lst -> content));
		if (newnode == NULL)
		{
			ft_lstclear(&newhead, del);
			return (NULL);
		}
		ft_lstadd_back(&newhead, newnode);
		lst = lst -> next;
	}
	return (newhead);
}
