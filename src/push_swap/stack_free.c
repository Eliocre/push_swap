/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:36:44 by eandre            #+#    #+#             */
/*   Updated: 2024/02/08 18:37:50 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_stackdelone(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*prev;

	prev = *stack;
	if (!(*stack))
		return ;
	while (*stack)
	{
		prev = *stack;
		*stack = (*stack)->next;
		free(prev);
	}
	*stack = NULL;
}
