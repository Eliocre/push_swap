/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:38:42 by eandre            #+#    #+#             */
/*   Updated: 2024/02/26 13:40:13 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"

void	checkchar(t_stack **lsta, t_stack **lstb, char *gnl);
void	push_(t_stack **src, t_stack **dest);
void	reverse_rotate_(t_stack **lst);
void	rotate_(t_stack **lst);
void	swap_(t_stack **lst);

#endif
