/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:03:14 by eandre            #+#    #+#             */
/*   Updated: 2024/02/22 23:39:14 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	findmax(t_stack *lst)
{
	int	tmp;

	tmp = INT_MIN;
	while (lst)
	{
		if (tmp < lst->content)
			tmp = lst->content;
		lst = lst->next;
	}
	return (tmp);
}

int	findmin(t_stack *lst)
{
	int	tmp;

	tmp = INT_MAX;
	while (lst)
	{
		if (tmp > lst->content)
			tmp = lst->content;
		lst = lst->next;
	}
	return (tmp);
}

int	find_location(t_stack **lst, int tofind)
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

int	find_closest(t_stack **lst, int nbr, int id)
{
	t_stack	*tmp;
	int		size;
	int		bool_;
	int		i;

	bool_ = TRUE;
	tmp = *lst;
	size = ft_stacksize(*lst);
	while (bool_ == TRUE)
	{
		i = 0;
		if (id == 0)
			nbr++;
		else
			nbr--;
		tmp = *lst;
		while (i++ < size)
		{
			if (tmp->content == nbr)
				bool_ = FALSE;
			tmp = tmp->next;
		}
	}
	return (nbr);
}
