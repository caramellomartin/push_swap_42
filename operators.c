/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:38:09 by jzaquina          #+#    #+#             */
/*   Updated: 2026/07/02 20:32:47 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// operators: sa, sb, ss,  pa, pb,  ra, rb, rr,  rra, rrb, rrr
// JOSE: ra, rb, rr,  rra, rrb, rrr

#include "push_swap.h"
#include <stdio.h>

void	ft_cpystack(t_stack *src, t_stack *dst)
{
	dst->index = src->index;
	dst->value = src->value;
}

void	ra(t_stack *stack)
{
	t_stack	*stk_first;

	stk_first = ft_new_node(0);
	ft_cpystack(stack, stk_first);
	while (1)
	{
		if (!stack->next)
		{
			ft_cpystack(stk_first, stack);
			break ;
		}
		ft_cpystack(stack->next, stack);
		stack = stack->next;
	}
	free(stk_first);
	write(1, "ra\n", 3);
}
