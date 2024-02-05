/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:32:26 by eandre            #+#    #+#             */
/*   Updated: 2024/02/05 18:54:05 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
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
		ft_printf("Error!\nNumber higher or lower than an int!");
		exit (1);
	}
	return (inturn * neg);
}

int	checkint(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	checkdouble(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			len = ft_strlen(argv[i]) + ft_strlen(argv[j]);
			if (ft_strncmp(argv[i], argv[j], len) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
			ft_printf("Error!\nNumber isnt an int!");
			exit (1);
		}
		ft_atoi_ps(argv[i]);
		i++;
	}
	if (checkdouble(argv) == 1)
	{
		ft_printf("Error!\nDouble detected!");
		exit (1);
	}
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

t_stack	*stash_init(char **argv)
{
	t_stack *return_v;
	int		i;

	return_v = ft_stacknew(atoi(argv[1]));
	return_v = return_v->next;
	i = 2;
	while (argv[i])
	{
		return_v->content = ft_atoi(argv[i]);
		i++;
		return_v = return_v->next;
	}
	return (return_v);
}

int	main(int argc, char **argv)
{
	t_stack	*tests;

	argchecker(argv, argc);
	tests = stash_init(argv);
	// ft_printf("%d", tests->content);
}

