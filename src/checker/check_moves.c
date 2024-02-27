/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:52:56 by eandre            #+#    #+#             */
/*   Updated: 2024/02/27 00:54:26 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static int	check_push(t_stack **lsta, t_stack **lstb, char *gnl)
{
	if (gnl[0] == 'p' && gnl[1] == 'a' && gnl[2] == '\n')
		return (push_(lstb, lsta), 1);
	else if (gnl[0] == 'p' && gnl[1] == 'b' && gnl[2] == '\n')
		return (push_(lsta, lstb), 1);
	return (0);
}

static int	check_swap(t_stack **lsta, t_stack **lstb, char *gnl)
{
	if (gnl[0] == 's' && gnl[1] == 'a' && gnl[2] == '\n')
		return (swap_(lsta), 1);
	else if (gnl[0] == 's' && gnl[1] == 'b' && gnl[2] == '\n')
		return (swap_(lstb), 1);
	else if (gnl[0] == 's' && gnl[1] == 's' && gnl[2] == '\n')
	{
		swap_(lsta);
		swap_(lstb);
		return (1);
	}
	return (0);
}

static int	check_rotate(t_stack **lsta, t_stack **lstb, char *gnl)
{
	if (gnl[0] == 'r' && gnl[1] == 'a' && gnl[2] == '\n')
		return (rotate_(lsta), 1);
	else if (gnl[0] == 'r' && gnl[1] == 'b' && gnl[2] == '\n')
		return (rotate_(lstb), 1);
	else if (gnl[0] == 'r' && gnl[1] == 'r' && gnl[2] == '\n')
	{
		rotate_(lsta);
		rotate_(lstb);
		return (1);
	}
	return (0);
}

static int	check_reverse_rotate(t_stack **lsta, t_stack **lstb, char *gnl)
{
	if (gnl[0] == 'r' && gnl[1] == 'r' && gnl[2] == 'a' && gnl[3] == '\n')
		return (reverse_rotate_(lsta), 1);
	else if (gnl[0] == 'r' && gnl[1] == 'r' && gnl[2] == 'b' && gnl[3] == '\n')
		return (reverse_rotate_(lstb), 1);
	else if (gnl[0] == 'r' && gnl[1] == 'r' && gnl[2] == 'r' && gnl[3] == '\n')
	{
		reverse_rotate_(lsta);
		reverse_rotate_(lstb);
		return (1);
	}
	return (0);
}

void	checkchar(t_stack **lsta, t_stack **lstb, char *gnl)
{
	int	oui;

	oui = 0;
	oui += check_push(lsta, lstb, gnl);
	oui += check_swap(lsta, lstb, gnl);
	oui += check_rotate(lsta, lstb, gnl);
	oui += check_reverse_rotate(lsta, lstb, gnl);
	if (oui == 0)
		write(2, "Error\n", 7);
}
