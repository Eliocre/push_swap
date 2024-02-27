/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:59:15 by eandre            #+#    #+#             */
/*   Updated: 2024/02/27 13:36:56 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../src/libft/include/libft.h"
# include <unistd.h>
# include <limits.h>

# define TRUE 0
# define FALSE 1
# define SUCCESS 0
# define FAILURE 1

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_moves;

void	checkdouble(t_stack *stack, char **argv);
int		checkint(char *argv);
char	**argchecker(char **argv, int argc);
t_moves	moves_init(void);
t_stack	*stack_init(char **argv, int id);
t_stack	*ft_stacknew(int content);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *stack);
void	ft_stackclear(t_stack **stack);
void	free_strs(char **strs);
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
int		findmax(t_stack *lst);
int		findmin(t_stack *lst);
int		find_location(t_stack **lst, int tofind);
int		valid_order(t_stack **lsta);
void	three_sort(t_stack **lsta);
void	four_sort(t_stack **lsta, t_stack **lstb, t_moves *moves);
void	push_back(t_stack **lsta, t_stack **lstb, t_moves *moves);
void	check_total(t_moves *moves, t_moves *cheap, int i);
void	check_double_moves(t_moves *moves);
void	do_cheap_moves(t_stack **lsta, t_stack **lstb, t_moves *moves);
void	move_cheapest(t_stack **lsta, t_stack **lstb, t_moves *moves);
void	get_top_stack_a(t_stack **ha, t_stack *lsta, int i, t_moves *moves);
void	new_elem_stack_a(t_stack **lsta, t_stack **lstb, t_moves *moves);
void	new_max_stack_a(t_stack **lsta, t_stack **lstb,
			t_moves *moves, int max);
void	new_min_stack_a(t_stack **lsta, t_stack **lstb,
			t_moves *moves, int min);
void	check_moves(t_stack **lsta, t_stack **lstb, t_moves *moves,
			t_moves *cheap);
void	new_max_stack_b(t_stack **lstb, t_moves *moves, int max);
void	new_elem_stack_b(t_stack **lstb, t_moves *moves, int num);
void	put_in_order_a(t_stack **lsta, t_stack **lstb, t_moves *moves, int min);
int		find_closest(t_stack **lst, int nbr, int id);
void	do_moves(t_stack **lsta, t_stack **lstb, t_moves *moves, int id);

#endif
