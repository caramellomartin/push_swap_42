/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcaram <marcaram@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:43:39 by marcaram          #+#    #+#             */
/*   Updated: 2026/07/16 16:43:44 by marcaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*ft_get_bench(void)
{
	static t_bench	bench;

	return (&bench);
}

static void	print_bench_ops_2(t_bench *b)
{
	ft_putstr_err("\n[bench] ra: ");
	ft_putnbr_err(b->ra);
	ft_putstr_err(" rb: ");
	ft_putnbr_err(b->rb);
	ft_putstr_err(" rr: ");
	ft_putnbr_err(b->rr);
	ft_putstr_err(" rra: ");
	ft_putnbr_err(b->rra);
	ft_putstr_err(" rrb: ");
	ft_putnbr_err(b->rrb);
	ft_putstr_err(" rrr: ");
	ft_putnbr_err(b->rrr);
	ft_putstr_err("\n");
}

static void	print_bench_ops_1(t_bench *b)
{
	ft_putstr_err("[bench] sa: ");
	ft_putnbr_err(b->sa);
	ft_putstr_err(" sb: ");
	ft_putnbr_err(b->sb);
	ft_putstr_err(" ss: ");
	ft_putnbr_err(b->ss);
	ft_putstr_err(" pa: ");
	ft_putnbr_err(b->pa);
	ft_putstr_err(" pb: ");
	ft_putnbr_err(b->pb);
	print_bench_ops_2(b);
}

void	print_benchmark(int strat, double disorder)
{
	t_bench	*b;

	b = ft_get_bench();
	ft_putstr_err("[bench] disorder: ");
	ft_putfloat_err(disorder);
	ft_putstr_err("[bench] strategy: ");
	if (b->is_adaptive == 4)
	{
		if (strat == 1)
			ft_putstr_err("Adaptive / O(n²)\n");
		else if (strat == 2)
			ft_putstr_err("Adaptive / O(n √n)\n");
		else
			ft_putstr_err("Adaptive / O(n log n)\n");
	}
	else if (strat == 1)
		ft_putstr_err("Simple / O(n²)\n");
	else if (strat == 2)
		ft_putstr_err("Medium / O(n √n)\n");
	else
		ft_putstr_err("Complex / O(n log n)\n");
	ft_putstr_err("[bench] total_ops: ");
	ft_putnbr_err(b->total);
	ft_putstr_err("\n");
	print_bench_ops_1(b);
}
