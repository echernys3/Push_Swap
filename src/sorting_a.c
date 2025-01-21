/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:45:18 by echernys          #+#    #+#             */
/*   Updated: 2025/01/21 16:04:09 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_is_smol(t_stack *stack_a, t_stacks **stacks);
void	last_is_smol(t_stack *last, t_stacks **stacks);

void	sort(t_stack *stack_a, t_stacks **stacks)
{
	t_stack	*last;
	t_stack	*secondtolast;

	last = ft_lstlast(stack_a);
	secondtolast = secondlast(stack_a);
	//on determine si le plus petit est dans les 2 premiers ou 2 derniers
	//check lequel des 2 premiers est plus petit
	if (stack_a->index < stack_a->next->index)
	{
		if (last->index < stack_a->index
			|| secondtolast->index < stack_a->index)
			last_is_smol(last, stacks);
		else
			first_is_smol((*stacks)->stack_a, stacks);
	}
	else if (stack_a->index > stack_a->next->index)
	{
		if (last->index < stack_a->next->index
			|| secondtolast->index < stack_a->next->index)
			last_is_smol(last, stacks);
		else
			first_is_smol((*stacks)->stack_a, stacks);
	}
	sort_in_b(stacks);
}

// une fois qu'on a trouvé le plus petit des 4, 
// on fait les checks nécessaires dans le stack b -> refaire la condition
	// if ((stack_a->index > (*stacks)->stack_b->index
	// 		&& stack_a->next->index > (*stacks)->stack_b->index
	// 		&& last->index > (*stacks)->stack_b->index
	// 		&& secondtolast->index > (*stacks)->stack_b->index)
	// 	|| !(*stacks)->stack_b)

void	first_is_smol(t_stack *stack_a, t_stacks **stacks)
{
	// si c'est le deuxieme, on fait un swap ou rotation selon si le 1er est plus petit que le 3eme
	if (stack_a->index > stack_a->next->index)
	{
		if (stack_a->index > stack_a->next->next->index)
			ra(stacks);
		sa(stacks, stacks);
	}
	// si le 1er est le plus petit des 3, on push tout simplement sinon il passe en dernier
	pb(stacks);
}

void	last_is_smol(t_stack *last, t_stacks **stacks)
{
	if ((secondlast((*stacks)->stack_a)->index) < last->index)
		rra(stacks);
	rra(stacks);
	pb(stacks);
}
	// check si l'avant dernier n'est pas plus petit, 
	// ensuite on reverserotate et push

// On fait LA MEME mais en INVERSE, 
// donc on trouve le plus petit des 4 et on le balance.
// Ensuite faut le comparer au deuxieme.
// Si on peut swap (= seulement si 2 elements ou bien i2 = i1-1)
// (Ne pas oublier qu'on pourrait double-swap (verifier si c'est efficace).)
// Si on ne swap pas, comparer au dernier 
// du stack b. Rotate s'il est plus petit encore.
// Le cas echeant, faire le suivant :
// Il suffit d'unE fonction qui check la 
// position du nouveau index contre ceux deja presents
// 			Si sort_in_b() <= size_b/2 (= dans la premiere moitie)
//				Faut faire la tech de (swap -> rb) fois b_finder, et faire le 
//				rrb fois b_finder pr remettre la liste.
// 		A l'enverse b_finder() > size_b/2 (= dans la deuxieme moitie)
//			Faire : (rrb -> swap) fois size_b - b_finder(), puis 
//			rb  fois  size_b - b_finder().
//
//      IDEE ABANDONNEE MAIS REUTILISABLE