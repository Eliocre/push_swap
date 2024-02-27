/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:36:44 by eandre            #+#    #+#             */
/*   Updated: 2024/02/26 23:38:15 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
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
