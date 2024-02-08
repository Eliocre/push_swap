/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:25:51 by eandre            #+#    #+#             */
/*   Updated: 2024/02/08 18:37:39 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (ret == NULL)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*end;

	if ((*stack) == NULL)
	{
		*stack = new;
		return ;
	}
	end = ft_stacklast(*stack);
	end->next = new;
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst != 0 && new != 0)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != 0)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
