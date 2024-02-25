/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:09:19 by eandre            #+#    #+#             */
/*   Updated: 2024/02/22 23:39:38 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	new_max_stack_b(t_stack **lstb, t_moves *moves, int max)
{
	int	i;
	int	size;

	moves->rb = 0;
	moves->rrb = 0;
	if ((*lstb)->content == max)
		return ;
	i = find_location(lstb, max);
	size = ft_stacksize(*lstb);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			moves->rrb = (size - i);
		else
			moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			moves->rrb = (size - i);
		else
			moves->rb = i;
	}
}

void	new_num_in_stack_b(t_stack **lstb, t_moves *moves, int num)
{
	int	i;
	int	size;
	int	nbr;

	moves->rb = 0;
	moves->rrb = 0;
	nbr = find_closest(lstb, num, 1);
	if ((*lstb)->content == nbr)
		return ;
	i = find_location(lstb, nbr);
	size = ft_stacksize(*lstb);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			moves->rrb = (size - i);
		else
			moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			moves->rrb = (size - i);
		else
			moves->rb = i;
	}
}
