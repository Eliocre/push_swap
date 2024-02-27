/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:32:26 by eandre            #+#    #+#             */
/*   Updated: 2024/02/26 17:15:13 by eandre           ###   ########.fr       */
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
	char	**oui;

	oui = argchecker(argv, argc);
	if (oui == NULL)
		lsta = stack_init(argv, 1);
	else
	{
		lsta = stack_init(oui, 0);
		free_strs(oui);
	}
	lstb = NULL;
	push_swap(&lsta, &lstb);
	ft_stackclear(&lsta);
	ft_stackclear(&lstb);
}
