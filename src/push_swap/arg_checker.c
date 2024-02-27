/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:34:18 by eandre            #+#    #+#             */
/*   Updated: 2024/02/26 18:08:43 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_atoi_ps(char **strs, int j, int id)
{
	long int	i;
	long int	inturn;
	long int	neg;

	i = 0;
	neg = 1;
	inturn = 0;
	while ((strs[j][i] >= 9 && strs[j][i] <= 13) || strs[j][i] == ' ')
		i++;
	if (strs[j][i] && (strs[j][i] == '-' || strs[j][i] == '+'))
	{
		if (strs[j][i] == '-')
			neg *= -1;
		i++;
	}
	while (strs[j][i] && strs[j][i] >= '0' && strs[j][i] <= '9')
		inturn = inturn * 10 + strs[j][i++] - 48;
	if (inturn > INT_MAX || inturn < INT_MIN)
	{
		write(2, "Error\n", 7);
		if (id == 0)
			free_strs(strs);
		exit (FAILURE);
	}
	return (inturn * neg);
}

void	check_int_min_max(char **argv, int i, int id)
{
	while (argv[i])
	{
		if (checkint(argv[i]) == 1)
		{
			write(2, "Error\n", 7);
			if (id == 0)
				free_strs(argv);
			exit (FAILURE);
		}
		if (id == 0)
			ft_atoi_ps(argv, i, 0);
		else
			ft_atoi_ps(argv, i, 1);
		i++;
	}
}

char	**argchecker(char **argv, int argc)
{
	char	**oui;

	if (argc < 2)
		exit (FAILURE);
	oui = NULL;
	if (argc == 2 && checkint(argv[1]) == 1)
	{
		oui = ft_split(argv[1], ' ');
		if (oui == NULL)
			exit (FAILURE);
		check_int_min_max(oui, 0, 0);
	}
	else
		check_int_min_max(argv, 1, 1);
	if (oui == NULL)
		return (NULL);
	return (oui);
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

void	checkdouble(t_stack *stack, char **argv)
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
				if (argv != NULL)
					free_strs(argv);
				exit (FAILURE);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}
