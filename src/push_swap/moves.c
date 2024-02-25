/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:34:45 by eandre            #+#    #+#             */
/*   Updated: 2024/02/22 23:35:11 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	do_moves(t_stack **lsta, t_stack **lstb, t_moves *moves, int id)
{
	while (moves->ra-- != 0)
		rotate_a(lsta);
	while (moves->rra-- != 0)
		reverse_rotate_a(lsta);
	if (id == 0)
	{
		push_a(lsta, lstb);
		rotate_a(lsta);
	}
	else if (id == 1)
		push_a(lsta, lstb);
	else
		return ;
}

void	do_cheap_moves(t_stack **lsta, t_stack **lstb, t_moves *moves)
{
	while (moves->ra-- != 0)
		rotate_a(lsta);
	while (moves->rb-- != 0)
		rotate_b(lstb);
	while (moves->rr-- != 0)
		rotate_ab(lsta, lstb);
	while (moves->rra-- != 0)
		reverse_rotate_a(lsta);
	while (moves->rrb-- != 0)
		reverse_rotate_b(lstb);
	while (moves->rrr-- != 0)
		reverse_rotate_ab(lsta, lstb);
	while (moves->pb-- != 0)
		push_b(lsta, lstb);
}
