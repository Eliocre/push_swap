/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:05:56 by eandre            #+#    #+#             */
/*   Updated: 2024/02/23 00:04:01 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_top_stack_a(t_stack **top, t_stack *lsta, int i, t_moves *moves)
{
	int	size;

	moves->pb = 1;
	moves->ra = 0;
	moves->rra = 0;
	if ((*top)->content == lsta->content)
		return ;
	size = ft_stacksize(*top);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			moves->rra = (size - i);
		else
			moves->ra = i;
	}
	else
	{
		if (i > size / 2)
			moves->rra = (size - i);
		else
			moves->ra = i;
	}
}

void	new_elem_stack_a(t_stack **lsta, t_stack **lstb, t_moves *moves)
{
	int	i;
	int	size;

	moves->ra = 0;
	moves->rra = 0;
	if ((*lsta)->content != find_closest(lsta, (*lstb)->content, 0))
	{
		i = find_location(lsta, find_closest(lsta, (*lstb)->content, 0));
		size = ft_stacksize(*lsta);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				moves->rra = (size - i);
			else
				moves->ra = i;
		}
		else
		{
			if (i > size / 2)
				moves->rra = (size - i);
			else
				moves->ra = i;
		}
	}
	do_moves(lsta, lstb, moves, 1);
}

void	new_max_stack_a(t_stack **lsta, t_stack **lstb, t_moves *moves, int max)
{
	int	i;
	int	size;

	moves->ra = 0;
	moves->rra = 0;
	if ((*lsta)->content != max)
	{
		i = find_location(lsta, max);
		size = ft_stacksize(*lsta);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				moves->rra = (size - i) - 1;
			else
				moves->ra = i + 1;
		}
		else
		{
			if (i > size / 2)
				moves->rra = (size - i) - 1;
			else
				moves->ra = i + 1;
		}
	}
	do_moves(lsta, lstb, moves, 0);
}

void	new_min_stack_a(t_stack **lsta, t_stack **lstb, t_moves *moves, int min)
{
	int	i;
	int	size;

	moves->ra = 0;
	moves->rra = 0;
	if ((*lsta)->content != min)
	{
		i = find_location(lsta, min);
		size = ft_stacksize(*lsta);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				moves->rra = (size - i);
			else
				moves->ra = i;
		}
		else
		{
			if (i > size / 2)
				moves->rra = (size - i);
			else
				moves->ra = i;
		}
	}
	do_moves(lsta, lstb, moves, 1);
}

void	put_in_order_a(t_stack **lsta, t_stack **lstb, t_moves *moves, int min)
{
	int	i;
	int	size;

	moves->ra = 0;
	moves->rra = 0;
	if ((*lsta)->content != min)
	{
		i = find_location(lsta, min);
		size = ft_stacksize(*lsta);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				moves->rra = (size - i);
			else
				moves->ra = i;
		}
		else
		{
			if (i > size / 2)
				moves->rra = (size - i);
			else
				moves->ra = i;
		}
	}
	do_moves(lsta, lstb, moves, 3);
}
