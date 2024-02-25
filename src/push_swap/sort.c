/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:24:44 by eandre            #+#    #+#             */
/*   Updated: 2024/02/22 23:36:29 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	three_sort(t_stack **lsta)
{
	int	nb1;
	int	nb2;
	int	nb3;

	nb1 = (*lsta)->content;
	nb2 = (*lsta)->next->content;
	nb3 = (*lsta)->next->next->content;
	if (nb1 > nb2 && nb1 > nb3 && nb2 < nb3)
		rotate_a(lsta);
	else if (nb1 < nb2 && nb1 > nb3 && nb2 > nb3)
		reverse_rotate_a(lsta);
	else if (nb1 > nb2 && nb1 < nb3 && nb2 < nb3)
		swap_a(lsta);
	else if (nb1 < nb2 && nb1 < nb3 && nb2 > nb3)
	{
		swap_a(lsta);
		rotate_a(lsta);
	}
	else if (nb1 > nb2 && nb1 > nb3 && nb2 > nb3)
	{
		swap_a(lsta);
		reverse_rotate_a(lsta);
	}
}

void	four_sort(t_stack **lsta, t_stack **lstb, t_moves *moves)
{
	push_b(lsta, lstb);
	three_sort(lsta);
	push_back(lsta, lstb, moves);
	ft_stackclear(lsta);
	ft_stackclear(lstb);
	exit (SUCCESS);
}

int	valid_order(t_stack **lsta)
{
	t_stack	*tmp;

	tmp = *lsta;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (FALSE);
		tmp = tmp->next;
	}
	ft_stackclear(lsta);
	return (TRUE);
}

void	push_back(t_stack **lsta, t_stack **lstb, t_moves *moves)
{
	int	min;
	int	max;

	while (*lstb)
	{
		min = findmin(*lsta);
		max = findmax(*lsta);
		if ((*lstb)->content < min)
			new_min_stack_a(lsta, lstb, moves, min);
		else if ((*lstb)->content > max)
			new_max_stack_a(lsta, lstb, moves, max);
		else
			new_elem_stack_a(lsta, lstb, moves);
	}
	min = findmin(*lsta);
	max = findmax(*lsta);
	put_in_order_a(lsta, lstb, moves, min);
	ft_stackclear(lsta);
	ft_stackclear(lstb);
}
