/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:19:52 by jzaquina          #+#    #+#             */
/*   Updated: 2026/07/18 11:20:29 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_data(char **argv, t_stack **stack_a)
{
	int		i;
	char	**sub;

	i = 1;
	while (argv[i])
	{
		sub = ft_split(argv[i], ' ');
		process_sub(sub, stack_a);
		ft_free_split(sub);
		i++;
	}
}

void	ft_exit(t_stack **stack_a, t_stack **stack_b)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	ft_error();
}

void	exec_op(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(stack_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(stack_b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(stack_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(stack_b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra\n", 3))
		rra(stack_a);
	else if (!ft_strncmp(line, "rrb\n", 3))
		rrb(stack_b);
	else if (!ft_strncmp(line, "rrr\n", 3))
		rrr(stack_a, stack_b);
	else
		ft_exit(stack_a, stack_b);
}

void	sort_a(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_op(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	ft_get_bench()->mode = 1;
	if (argc <= 1)
		return (0);
	parse_data(argv, &stack_a);
	sort_a(&stack_a, &stack_b);
	if ((stack_a == NULL || is_sorted(stack_a)) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
