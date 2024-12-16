/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:45:18 by echernys          #+#    #+#             */
/*   Updated: 2024/12/16 17:06:43 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stacks **stacks)
{
	t_stack *last;

	last = ft_lstlast(stack_a);
	//check si le 1er, 2eme ou 2 derniers dans a sont TOUS plus grand que le premier dans b
	if ((stack_a->index > (*stacks)->stack_b->index
			&& stack_a->next->index > (*stacks)->stack_b->index
			&& last->index > (*stacks)->stack_b->index
			&& secondlast(stack_a)->index > (*stacks)->stack_b->index)
		|| !(*stacks)->stack_b)
	{
		//on determine si c'est dans les 2 premiers ou 2 derniers
		if (last->index < stack_a->index
			|| (secondlast(stack_a)->index) < last->index)
			last_a_bigger(last, stacks);
		else
			a_is_bigger(stacks);
	}
	else
	// si on passe ici, c'est qu'on a un chiffre qui doit etre repositionne dans b
	{
		if ()
		sort_a_is_smaller(stacks);
	}
}

void	a_is_bigger(t_stack stack_a, t_stacks **stacks)
{

	// si c'est le deuxieme, on fait un swap ou rotation selon si le 1er est plus petit que le 3eme
	if (stack_a->index > stack_a->next->index)
	{
		if (stack_a->index > stack_a->next->next->index)
			ra(stacks);
		sa(stacks);
	}
	// si le 1er est le plus petit des 3, on push tout simplement sinon il passe en dernier
	pb(stacks);
}

void	last_a_bigger(t_stack *last, t_stacks **stacks)
{
	// check si l'avant dernier n'est pas plus petit, ensuite on reverserotate et push
	if ((secondlast((*stacks->stack_a))->index) < last->index)
		rra(stacks);
	rra(stacks);
	pb(stacks);
}

void	a_is_smaller(t_stacks **stacks)
{
	// On fait LA MEME mais en INVERSE, donc on trouve le plus petit des 4 et on le balance.
	// Ensuite faut le comparer au deuxieme.
	// Si on peut swap (= seulement si 2 elements ou bien i2 = i1-1)
	// (Ne pas oublier qu'on pourrait double-swap (verifier si c'est efficace).)
	// Si on ne swap pas, comparer au dernier du stack b. Rotate s'il est plus petit encore.
	// Le cas echeant, faire le suivant :
	// Il suffit d'un fonction qui check la position du nouveau index contre ceux deja presents
	// 			Si b_finder() <= size_b/2 (= dans la premiere moitie)
	//				Faut faire la tech de (swap -> rb) fois b_finder, et faire le rrb fois b_finder pr remettre la liste.
	// 		A l'enverse b_finder() > size_b/2 (= dans la deuxieme moitie)
	//			Faire : (rrb -> swap) fois size_b - b_finder(), puis rb  fois  size_b - b_finder().
}
