/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:35:07 by jzaquina          #+#    #+#             */
/*   Updated: 2026/07/07 14:17:22 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack *stack)
{
	t_stack	*stk_aux;
	t_stack	*stk_temp;
	t_stack	*stk_temp2;

	stk_aux = stack;
	stk_temp = ft_new_node(0);
	stk_temp2 = ft_new_node(0);
	ft_cpystack(stk_aux->next, stk_temp);
	ft_cpystack(stk_aux, stk_aux->next);
	stk_aux = stk_aux->next;
	while (stk_aux->next)
	{
		ft_cpystack(stk_aux->next, stk_temp2);
		ft_cpystack(stk_temp, stk_aux->next);
		ft_cpystack(stk_temp2, stk_temp);
		if (!stk_aux->next->next)
			ft_cpystack(stk_temp, stack);
		stk_aux = stk_aux->next;
	}
	free(stk_temp);
	free(stk_temp2);
}

void	rra(t_stack *stack_a)
{
	r_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rra(t_stack *stack_b)
{
	r_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	write(1, "rrr\n", 4);
}
