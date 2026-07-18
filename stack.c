/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:45:35 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/18 11:35:00 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> index = -1;
	new -> next = NULL;
	return (new);
}

void	ft_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*tmp;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new_node;
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)-> next;
		free(*stack);
		*stack = tmp;
	}
}

int	is_sorted(t_stack *stack)
{
	int	size;

	size = ft_stack_size(stack);
	if (!stack || size < 2)
		return (1);
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
