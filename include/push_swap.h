/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:59:15 by eandre            #+#    #+#             */
/*   Updated: 2024/02/05 17:55:50 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "src/libft/include/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

#endif