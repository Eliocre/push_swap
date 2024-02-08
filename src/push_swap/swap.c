/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:25:18 by eandre            #+#    #+#             */
/*   Updated: 2024/02/08 20:29:25 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap_(t_stack **lst)
{
	int	tmp;

	if ((*lst)->next && (*lst))
	{
		tmp = (*lst)->next->content;
		(*lst)->next->content = (*lst)->content;
		(*lst)->content = tmp;
	}
}

void	swap_a(t_stack **lsta)
{
	swap_(lsta);
	ft_printf("sa\n");
}

void	swap_b(t_stack **lstb)
{
	swap_(lstb);
	ft_printf("sb\n");
}

void	swap_ab(t_stack **lsta, t_stack **lstb)
{
	swap_(lsta);
	swap_(lstb);
	ft_printf("ss\n");
}
