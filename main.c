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

int	main(int argc, char **argv)
{
	int		strat;
	int		bench_mode;
	int		*final_array;
	int		total_numbers;
	t_stack	*stack_a;

	strat = 4;
	bench_mode = 0;
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
	debug_print_stack(stack_a, "Stack A");
	// JOSE: OJOO!!. TESTING OPERATORS
	ra(&stack_a);
	debug_print_stack(stack_a, "ra: new Stack A");
	rra(&stack_a);
	debug_print_stack(stack_a, "rra: new Stack A");
	// JOSE: FIN
	ft_free_stack(&stack_a);
	return (0);
}
