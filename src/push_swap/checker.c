/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:34:18 by eandre            #+#    #+#             */
/*   Updated: 2024/02/08 18:38:45 by eandre           ###   ########.fr       */
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
