/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:06:51 by eandre            #+#    #+#             */
/*   Updated: 2024/02/08 20:36:24 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push_(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src != NULL)
	{
		tmp = (*src)->next;
		(*src)->next = *dest;
		*dest = *src;
		*src = tmp;
	}
}

void	push_a(t_stack **lsta, t_stack **lstb)
{
	push_(lstb, lsta);
	ft_printf("pa\n");
}

void	push_b(t_stack **lsta, t_stack **lstb)
{
	push_(lsta, lstb);
	ft_printf("pb\n");
}
