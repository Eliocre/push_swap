/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:26:48 by eandre            #+#    #+#             */
/*   Updated: 2024/02/27 13:36:46 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_cheapest(t_stack **lsta, t_stack **lstb, t_moves *moves)
{
	t_moves	cheap;

	cheap = moves_init();
	while (ft_stacksize(*lsta) != 3)
	{
		check_moves(lsta, lstb, moves, &cheap);
		do_cheap_moves(lsta, lstb, &cheap);
	}
}

void	check_moves(t_stack **lsta, t_stack **lstb, t_moves *moves,
t_moves *cheap)
{
	int		i;
	int		max;
	int		min;
	int		size;
	t_stack	*tmp;

	tmp = *lsta;
	size = ft_stacksize(*lsta);
	min = findmin(*lstb);
	max = findmax(*lstb);
	i = 0;
	while (i++ < size)
	{
		get_top_stack_a(lsta, tmp, i - 1, moves);
		if (tmp->content > max || tmp->content < min)
			new_max_stack_b(lstb, moves, max);
		else
			new_elem_stack_b(lstb, moves, tmp->content);
		check_double_moves(moves);
		check_total(moves, cheap, i);
		tmp = tmp->next;
	}
}

void	check_double_moves(t_moves *moves)
{
	moves->rr = 0;
	moves->rrr = 0;
	while (moves->ra != 0 && moves->rb != 0)
	{
		moves->ra--;
		moves->rb--;
		moves->rr++;
	}
	while (moves->rra != 0 && moves->rrb != 0)
	{
		moves->rra--;
		moves->rrb--;
		moves->rrr++;
	}
}

void	check_total(t_moves *moves, t_moves *cheap, int i)
{
	moves->total = moves->pb + moves->ra
		+ moves->rb + moves->rr + moves->rra
		+ moves->rrb + moves->rrr;
	if (i == 1 || (cheap->total > moves->total))
	{
		cheap->total = moves->total;
		cheap->pb = moves->pb;
		cheap->ra = moves->ra;
		cheap->rb = moves->rb;
		cheap->rr = moves->rr;
		cheap->rra = moves->rra;
		cheap->rrb = moves->rrb;
		cheap->rrr = moves->rrr;
	}
}
