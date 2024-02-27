/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:35:57 by eandre            #+#    #+#             */
/*   Updated: 2024/02/27 14:10:25 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*stack_init(char **argv, int id)
{
	t_stack	*return_v;
	t_stack	*stack;
	int		i;

	i = checkint(argv[0]);
	return_v = NULL;
	while (argv[i])
	{
		stack = ft_stacknew(atoi(argv[i++]));
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
	}
	if (id == 0)
		checkdouble(&return_v, argv);
	else
		checkdouble(&return_v, NULL);
	return (return_v);
}

t_moves	moves_init(void)
{
	t_moves	return_v;

	return_v.pa = 0;
	return_v.pb = 0;
	return_v.sa = 0;
	return_v.sb = 0;
	return_v.ss = 0;
	return_v.ra = 0;
	return_v.rb = 0;
	return_v.rr = 0;
	return_v.rra = 0;
	return_v.rrb = 0;
	return_v.rrr = 0;
	return_v.total = 0;
	return (return_v);
}
