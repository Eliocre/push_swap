/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:32:26 by eandre            #+#    #+#             */
/*   Updated: 2024/02/13 19:04:35 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_swap(t_stack **lsta, t_stack **lstb)
{
	t_moves	moves_;

	moves_ = moves_init();
	if (valid_order(lsta) == TRUE)
		exit (SUCCESS);
	if (ft_stacksize(*lsta) == 2)
	{
		swap_a(lsta);
		ft_stackclear(lsta);
		exit (SUCCESS);
	}
	if (ft_stacksize(*lsta) == 3)
	{
		three_sort(lsta);
		ft_stackclear(lsta);
		exit (SUCCESS);
	}
	if (ft_stacksize(*lsta) == 4)
		four_sort(lsta, lstb, &moves_);
	push_b(lsta, lstb);
	push_b(lsta, lstb);
	move_cheapest(lsta, lstb, &moves_);
	three_sort(lsta);
	push_back(lsta, lstb, &moves_);
}

int	main(int argc, char **argv)
{
	t_stack	*lsta;
	t_stack	*lstb;

	argchecker(argv, argc);
	lsta = stack_init(argv);
	lstb = NULL;
	push_swap(&lsta, &lstb);
	ft_stackclear(&lsta);
	ft_stackclear(&lstb);
}
