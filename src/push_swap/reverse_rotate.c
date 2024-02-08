/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:28:03 by eandre            #+#    #+#             */
/*   Updated: 2024/02/08 21:05:11 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_stack	*ft_stackbeforelast(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

static void	reverse_rotate_(t_stack **lst)
{
	t_stack	*last;
	t_stack	*beforelast;

	last = ft_stacklast(*lst);
	beforelast = ft_stackbeforelast(*lst);
	ft_stackadd_front(lst, last);
	beforelast->next = NULL;
}

void	reverse_rotate_a(t_stack **lsta)
{
	reverse_rotate_(lsta);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **lstb)
{
	reverse_rotate_(lstb);
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_stack **lsta, t_stack **lstb)
{
	reverse_rotate_(lsta);
	reverse_rotate_(lstb);
	ft_printf("rrr\n");
}
