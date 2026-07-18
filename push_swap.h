/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:48:56 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/17 21:33:50 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flag
{
	char	*name;
	int		value;
}	t_flag;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	is_adaptive;
	int	total;
	int	mode;
}	t_bench;

/* --- utils.c --- */
size_t	ft_strlen(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_stack_size(t_stack *stack);
void	ft_error(void);

/* --- print_utils.c --- */
void	ft_putstr_err(char *str);
void	ft_putnbr_err(int n);
void	ft_putfloat_err(double disorder);
void	ft_print_move(char *move);

/* --- bench.c --- */
t_bench	*ft_get_bench(void);
void	print_benchmark(int strat, double disorder);

/* --- split.c --- */
void	ft_free_split(char **split);
char	**ft_split(char const *s, char c);

/* --- parsing_utils.c --- */
int		is_flag(char *argv, int *strat, int *bench);
int		ft_checkdig(const char *str, int sign, int *result);
int		ft_isnumber(const char *str, int *result);
int		ft_isduplicate(t_stack *stack, int val);

/* --- parsing.c --- */
void	ft_parse_args(char **argv, int *strat, int *bench, t_stack **stack_a);
void	process_sub(char **sub, t_stack **stack_a);

/* --- stack.c --- */
t_stack	*ft_new_node(int value);
void	ft_add_back(t_stack **stack, t_stack *new_node);
void	ft_free_stack(t_stack **stack);

/* --- index.c --- */
void	ft_assign_index(t_stack *stack);

/* --- swap.c --- */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/* --- push.c --- */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/* --- rotate.c --- */
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/* --- reverse_rotate.c --- */
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* --- disorder.c --- */
double	ft_compute_disorder(t_stack *stack);

/* --- sort.c --- */
void	ft_sort_three(t_stack **stack_a);
int		ft_get_min_i(t_stack *stack, int min_value);
int		ft_find_lowest(t_stack *stack);
void	execute_strategy(int strat, t_stack **a, t_stack **b);

/* --- sort_simple.c --- */
void	ft_sort_simple(t_stack **stack_a, t_stack **stack_b);

/* --- sort_medium.c --- */
void	ft_sort_medium(t_stack **stack_a, t_stack **stack_b);

/* --- sort_complex.c --- */
void	ft_sort_complex(t_stack **stack_a, t_stack **stack_b);

#endif
