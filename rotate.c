/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:38:09 by jzaquina          #+#    #+#             */
/*   Updated: 2026/07/07 10:41:17 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
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
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
