/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:43:58 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:44:01 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_adaptive(double disorder, int *strat)
{
	if (disorder < 0.2)
		*strat = 1;
	else if (disorder < 0.5)
		*strat = 2;
	else
		*strat = 3;
}

static void	run_push_swap(t_stack **stack_a, int strat, int bench, double dis)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (dis == 0.0)
	{
		if (bench)
			print_benchmark(strat, dis);
		return ;
	}
	execute_strategy(strat, stack_a, &stack_b);
	if (bench)
		print_benchmark(strat, dis);
	ft_free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	int		strat;
	int		bench_mode;
	double	disorder;
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	strat = 4;
	ft_get_bench()->is_adaptive = 4;
	bench_mode = 0;
	stack_a = NULL;
	ft_parse_args(argv, &strat, &bench_mode, &stack_a);
	if (!stack_a)
		ft_error();
	ft_assign_index(stack_a);
	disorder = ft_compute_disorder(stack_a);
	if (strat == 4)
		handle_adaptive(disorder, &strat);
	run_push_swap(&stack_a, strat, bench_mode, disorder);
	ft_free_stack(&stack_a);
	return (0);
}
