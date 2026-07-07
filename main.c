#include "push_swap.h"

static void	process_sub(char **sub, int *arr, int *total)
{
	int	j;
	int	val;

	j = 0;
	while (sub[j])
	{
		if (!ft_isnumber(sub[j], &val) || ft_isduplicate(arr, *total, val))
		{
			ft_free_split(sub);
			ft_error(arr);
		}
		arr[(*total)++] = val;
		j++;
	}
}

static int	ft_parse_args(char **argv, int *strat, int *bench, int *arr)
{
	int		i;
	int		total;
	char	**sub;

	i = 1;
	total = 0;
	while (argv[i])
	{
		if (is_flag(argv[i], strat, bench))
		{
			i++;
			continue ;
		}
		sub = ft_split(argv[i], ' ');
		if (!sub || !sub[0])
		{
			ft_free_split(sub);
			ft_error(arr);
		}
		process_sub(sub, arr, &total);
		ft_free_split(sub);
		i++;
	}
	return (total);
}

static void	handle_adaptive(t_stack *stack_a, int *strat)
{
	double	disorder;
	
	disorder = ft_compute_disorder(stack_a);
	if (disorder < 0.2)
		*strat = 1;
	else if (disorder < 0.5)
		*strat = 2;
	else
		*strat = 3;
}

static void	execute_strategy(int strat, t_stack **a, t_stack **b)
{
	if (strat == 1)
		ft_sort_simple(a, b);
	else if (strat == 2)
		ft_sort_medium(a, b);
	else if (strat == 3)
		ft_sort_complex(a, b);
}

int	main(int argc, char **argv)
{
	int		strat;
	int		bench_mode;
	int		*final_array;
	int		total_numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	strat = 4;
	bench_mode = 0;
	stack_b = NULL;
	final_array = malloc(sizeof(int) * (argc * 10));
	if (argc < 2 || !final_array)
	{
		free(final_array);
		return (0);
	}
	total_numbers = ft_parse_args(argv, &strat, &bench_mode, final_array);
	stack_a = ft_init_stack(final_array, total_numbers);
	free(final_array);
	if (!stack_a)
		ft_error(NULL);
	ft_assign_index(stack_a);
	if (strat == 4)
		handle_adaptive(stack_a, &strat);
	execute_strategy(strat, &stack_a, &stack_b);
	if (bench_mode)
	{
		fprintf(stderr, "\n=== BENCHMARK REPORT ===\n");
		fprintf(stderr, "Estrategia final usada: %d\n", strat);
		fprintf(stderr, "Total de movimientos:   %d\n", ft_track_moves(0));
		fprintf(stderr, "========================\n\n");
	}

	debug_print_stack(stack_a, "Stack A");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
	return (0);
}
