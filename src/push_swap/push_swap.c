/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:32:26 by eandre            #+#    #+#             */
/*   Updated: 2024/02/13 19:04:35 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

int	findmax(t_stack *lsta)
{
	int	tmp;

	tmp = INT_MIN;
	while (lsta)
	{
		if (tmp < lsta->content)
			tmp = lsta->content;
		lsta = lsta->next;
	}
	return (tmp);
}

int	findmin(t_stack *lsta)
{
	int	tmp;

	tmp = INT_MAX;
	while (lsta)
	{
		if (tmp > lsta->content)
			tmp = lsta->content;
		lsta = lsta->next;
	}
	return (tmp);
}

int	closest(t_stack **lst, int nb)
{
	int		tmp;
	t_stack	*stack;

	tmp = INT_MAX;
	stack = *lst;
	while (stack)
	{
		if (stack->content > nb && stack->content < tmp)
			tmp = stack->content;
		stack = stack->next;
	}
	return (tmp);
}

int	findlocation(t_stack **lst, int tofind)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = *lst;
	while (stack && stack->content != tofind)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	push_swap(t_stack **lsta, t_stack **lstb)
{
	int		len;
	int		max;
	int		min;
	int		oui;

	max = findmax(*lsta);
	min = findmin(*lsta);
	len = ft_stacksize(*lsta);
	while (len > 0)
	{
		if ((*lsta) && (*lsta)->next && (*lsta)->next->content > (*lsta)->content)
			swap_a(lsta);
		reverse_rotate_a(lsta);
		if ((*lsta)->content <= max / 5)
			push_b(lsta, lstb);
		len--;
	}
	len = ft_stacksize(*lsta);
	while (len > 0)
	{
		if ((*lsta) && (*lsta)->next && (*lsta)->next->content > (*lsta)->content)
			swap_a(lsta);
		reverse_rotate_a(lsta);
		if ((*lsta)->content <= max / 4)
			push_b(lsta, lstb);
		len--;
	}
	len = ft_stacksize(*lsta);
	while (len > 0)
	{
		if ((*lsta) && (*lsta)->next && (*lsta)->next->content > (*lsta)->content)
			swap_a(lsta);
		reverse_rotate_a(lsta);
		if ((*lsta)->content <= max / 3)
			push_b(lsta, lstb);
		len--;
	}
	len = ft_stacksize(*lsta);
	while (len > 0)
	{
		if ((*lsta) && (*lsta)->next && (*lsta)->next->content > (*lsta)->content)
			swap_a(lsta);
		reverse_rotate_a(lsta);
		if ((*lsta)->content <= max / 2)
			push_b(lsta, lstb);
		len--;
	}
	len = ft_stacksize(*lsta);
	while (len > 0)
	{
		if ((*lsta) && (*lsta)->next && (*lsta)->next->content > (*lsta)->content)
			swap_a(lsta);
		reverse_rotate_a(lsta);
		if ((*lsta)->content <= max - 100)
			push_b(lsta, lstb);
		len--;
	}
	while ((*lstb)->content != min)
		rotate_b(lstb);
	push_a(lsta, lstb);
	len = ft_stacksize(*lstb);
	while (*lstb)
	{
		oui = findlocation(lstb, closest(lstb, min));
		while (closest(lstb, min) != (*lstb)->content)
		{
			if (oui < len / 2)
				rotate_b(lstb); 
			else if (oui > len / 2)
				reverse_rotate_b(lstb);
		}
		min = (*lstb)->content;
		push_a(lsta, lstb);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*lsta;
	t_stack	*lstb;

	argchecker(argv, argc);
	lsta = stack_init(argv);
	lstb = NULL;
	push_swap(&lsta, &lstb);
	// swap_(&lsta);
	// ft_printf("%d ", lsta->next->content);
	// ft_printf("%d ", lsta->content);
	// ft_printf("%d ", lsta->next->content);
	// ft_printf("%d ", lsta->next->next->content);
	// ft_printf("%d\n", lsta->next->next->next->content);
	// push_a(&lsta, &lstb);
	// reverse_rotate_a(&lsta);
	// reverse_rotate_b(&lstb);
	// ft_printf("%d\n", lstb->content);
	// ft_printf("%d ", lsta->content);
	// ft_printf("%d ", lsta->next->content);
	// ft_printf("%d ", lsta->next->next->content);
	// ft_printf("%d\n", lsta->next->next->next->content);
	ft_stackclear(&lsta);
	ft_stackclear(&lstb);
}
