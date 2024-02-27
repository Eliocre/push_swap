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

void	checker(t_stack **lsta, t_stack **lstb, char *gnl)
{
	char	*lastgnl;

	while (gnl && gnl[0] != '\n')
	{
		lastgnl = gnl;
		checkchar(lsta, lstb, gnl);
		gnl = get_next_line(0);
		free(lastgnl);
	}
	if (*lstb != NULL)
		ft_printf("KO\n");
	if (valid_order(lsta) == FALSE)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(gnl);
}

int	main(int argc, char **argv)
{
	t_stack	*lsta;
	t_stack	*lstb;
	char	**oui;
	char	*gnl;

	oui = argchecker(argv, argc);
	if (oui == NULL)
		lsta = stack_init(argv, 1);
	else
	{
		lsta = stack_init(oui, 0);
		free_strs(oui);
	}
	lstb = NULL;
	gnl = get_next_line(0);
	if (gnl == NULL && valid_order(&lsta) == FALSE)
		ft_printf("KO\n");
	else if (gnl == NULL && valid_order(&lsta) == TRUE)
		ft_printf("OK\n");
	else
		checker(&lsta, &lstb, gnl);
	ft_stackclear(&lsta);
	ft_stackclear(&lstb);
}
