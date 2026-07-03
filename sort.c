#include "push_swap.h"

static	int	ft_find_highest(t_stack *stack)
{
	int	highest;

	highest = stack -> value;
	while (stack)
	{
		if (stack -> value > highest)
			highest = stack -> value;
		stack = stack -> next;
	}
	return (highest);
}

static	int	ft_get_min_i(t_stack *stack, int min_value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack -> value == min_value)
			return (i);
		i++;
		stack = stack -> next;
	}
	return (i);
}

static	int	ft_find_lowest(t_stack *stack)
{
	int	lowest;

	lowest = stack -> value;
	while (stack)
	{
		if (stack -> value < lowest)
			lowest = stack -> value;
		stack = stack -> next;
	}
	return (lowest);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	highest;

	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	highest = ft_find_highest(*stack_a);
	//Si el mayor esta arriba o en medio, lo mandamos al fondo
	if ((*stack_a)-> value == highest)
		ra(stack_a);
	else if ((*stack_a)-> next -> value == highest)
		rra(stack_a);
	//Si los dos primeros estan invertidos
	if ((*stack_a)-> value > (*stack_a)-> next -> value)
		sa(stack_a);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest;
	int	i;

	// Pasamos los 2 numeros mas chicos a B para que queden 3 en A y usar sort three
	while (ft_stack_size(*stack_a) > 3)
	{
		lowest = ft_find_lowest(*stack_a);
		i = ft_get_min_i(*stack_a, lowest);
		//Si esta en la segunda mitad usamos rra, de otra forma ra
		while ((*stack_a)-> value != lowest)
		{
			if (i <= ft_stack_size(*stack_a) / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	//ordenamos los 3 restantes
	ft_sort_three(stack_a);
	//pasamos al stak A los que dejamos en el B
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
