/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:55:42 by eandre            #+#    #+#             */
/*   Updated: 2024/02/08 21:12:43 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate_(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = NULL;
		ft_stackadd_back(lst, tmp);
	}
}

void	rotate_a(t_stack **lsta)
{
	rotate_(lsta);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **lstb)
{
	rotate_(lstb);
	ft_printf("rb\n");
}

void	rotate_ab(t_stack **lsta, t_stack **lstb)
{
	rotate_(lsta);
	rotate_(lstb);
	ft_printf("rr\n");
}
