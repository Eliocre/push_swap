/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:38:23 by eandre            #+#    #+#             */
/*   Updated: 2024/02/26 18:54:05 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
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

t_stack	*stack_init(char **argv)
{
	t_stack	*return_v;
	t_stack	*stack;
	int		i;

	i = 1;
	return_v = NULL;
	while (argv[i])
	{
		stack = ft_stacknew(atoi(argv[i]));
		if (stack == NULL)
		{
			if (return_v != NULL)
				ft_stackclear(&return_v);
			exit (FAILURE);
		}
		if (return_v != NULL)
			ft_stackadd_back(&return_v, stack);
		else
			return_v = stack;
		i++;
	}
	return (return_v);
}

int	main(int argc, char **argv)
{
	t_stack	*lsta;
	t_stack	*lstb;
	// char	*gnl;
	// char	*lastgnl;
	char	*all;

	if (argc < 2)
		return (0);
	lsta = stack_init(argv);
	lstb = NULL;
	all = NULL;
	free(all);
}