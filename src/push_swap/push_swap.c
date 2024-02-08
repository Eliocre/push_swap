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

int	main(int argc, char **argv)
{
	t_stack	*lsta;
	// t_stack	*lstb;

	argchecker(argv, argc);
	lsta = stack_init(argv);
	// lstb = NULL;
	// swap_(&lsta);
	// ft_printf("%d ", lsta->next->content);
	ft_printf("%d ", lsta->content);
	ft_printf("%d ", lsta->next->content);
	ft_printf("%d ", lsta->next->next->content);
	ft_printf("%d\n", lsta->next->next->next->content);
	// push_b(&lsta, &lstb);
	// push_a(&lsta, &lstb);
	reverse_rotate_a(&lsta);
	// ft_printf("%d\n", lstb->content);
	ft_printf("%d ", lsta->content);
	ft_printf("%d ", lsta->next->content);
	ft_printf("%d ", lsta->next->next->content);
	ft_printf("%d\n", lsta->next->next->next->content);
	ft_stackclear(&lsta);
	// ft_stackclear(&lstb);
}
