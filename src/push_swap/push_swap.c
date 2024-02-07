/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:32:26 by eandre            #+#    #+#             */
/*   Updated: 2024/02/07 18:06:03 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <limits.h>

int	ft_atoi_ps(const char *str)
{
	long int	i;
	long int	inturn;
	long int	neg;

	i = 0;
	neg = 1;
	inturn = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		inturn = inturn * 10 + str[i++] - 48;
	if (inturn > INT_MAX || inturn < INT_MIN)
	{
		write(2, "Error\n", 7);
		exit (1);
	}
	return (inturn * neg);
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
	while (stack != 0)
	{
		if (stack->next == 0)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*end;

	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	end = ft_stacklast(*stack);
	end->next = new;
}

void	swap_(t_stack **lst)
{
	int	tmp;

	if ((*lst)->next != NULL && (*lst) != NULL)
	{
		tmp = (*lst)->next->content;
		(*lst)->next->content = (*lst)->content;
		(*lst)->content = tmp;
	}
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst != 0 && new != 0)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	push_a(t_stack **lsta, t_stack **lstb)
{
	t_stack	*tmp;

	if (lstb != NULL)
	{
		tmp = ft_stacknew((*lsta)->content);
		if (tmp == NULL)
		{
			ft_stackclear(lsta);
			ft_stackclear(lstb);
		}
		ft_stackadd_front(lstb, tmp);
	}
}

void	push_b(t_stack **lsta, t_stack **lstb)
{
	t_stack	*tmp;

	if (lsta != NULL)
	{
		tmp = ft_stacknew((*lstb)->content);
		if (tmp == NULL)
		{
			ft_stackclear(lstb);
			ft_stackclear(lsta);
		}
		ft_stackadd_front(lsta, tmp);
	}
}

void	swap_ab(t_stack **lsta, t_stack **lstb)	
{
	swap_(lsta);
	swap_(lstb);
}

int	checkint(char *argv)
{
	int	i;

	i = 0;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == ' ')
		i++;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	checkdouble(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	**start;

	start = &stack;
	while (stack && stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->content == stack->content)
			{
				ft_stackclear(start);
				write(2, "Error\n", 7);
				exit (1);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

void	argchecker(char **argv, int argc)
{
	int	i;

	if (argc < 2)
		exit (1);
	i = 1;
	while (argv[i])
	{
		if (checkint(argv[i]) == 1)
		{
			write(2, "Error\n", 7);
			exit (1);
		}
		ft_atoi_ps(argv[i]);
		i++;
	}
}

t_stack	*stack_init(char **argv)
{
	t_stack *return_v;
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
			exit (1);
		}
		if (return_v != NULL)
			ft_stackadd_back(&return_v, stack);
		else
			return_v = stack;
		i++;
	}
	checkdouble(return_v);
	return (return_v);
}

int	main(int argc, char **argv)
{
	t_stack	*lsta;
	t_stack	*lstb;

	argchecker(argv, argc);
	lsta = stack_init(argv);
	lstb = NULL;
	ft_printf("%d ", lsta->content);
	ft_printf("%d ", lsta->next->content);
	ft_printf("%d\n", lsta->next->next->content);
	swap_(&lsta);
	push_(&lsta, &lstb);
	ft_printf("%d\n", lstb->content);
	ft_printf("%d ", lsta->next->content);
	ft_printf("%d\n", lsta->next->next->content);
	ft_stackclear(&lsta);
	ft_stackclear(&lstb);
}

