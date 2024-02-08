/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:59:15 by eandre            #+#    #+#             */
/*   Updated: 2024/02/07 14:18:27 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../src/libft/include/libft.h"
# include <unistd.h>

# define TRUE 0
# define FALSE 1

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacknew(int content);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *stack);
void	ft_stackdelone(t_stack *stack);
void	ft_stackclear(t_stack **stack);
void	swap_a(t_stack **lsta);
void	swap_b(t_stack **lstb);
void	swap_ab(t_stack **lsta, t_stack **lstb);
void	rotate_a(t_stack **lsta);
void	rotate_b(t_stack **lstb);
void	reverse_rotate_a(t_stack **lsta);
void	reverse_rotate_b(t_stack **lstb);
void	reverse_rotate_ab(t_stack **lsta, t_stack **lstb);
void	rotate_ab(t_stack **lsta, t_stack **lstb);
void	push_a(t_stack **lsta, t_stack **lstb);
void	push_b(t_stack **lsta, t_stack **lstb);
void	checkdouble(t_stack *stack);
int		checkint(char *argv);
void	argchecker(char **argv, int argc);

#endif
