/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:09:19 by eandre            #+#    #+#             */
/*   Updated: 2024/02/27 13:41:22 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	new_max_stack_b(t_stack **lstb, t_moves *moves, int max)
{
	int	i;
	int	size;

	moves->rb = 0;
	moves->rrb = 0;
	if ((*lstb)->content != max)
	{
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
}

void	new_elem_stack_b(t_stack **lstb, t_moves *moves, int num)
{
	int	i;
	int	size;

	moves->rb = 0;
	moves->rrb = 0;
	if ((*lstb)->content != find_closest(lstb, num, 1))
	{
		i = find_location(lstb, find_closest(lstb, num, 1));
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
}
