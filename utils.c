#include "push_swap.h"

size_t	ft_strlen(const char *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_error(int *arr)
{
	if (arr)
		free(arr);
	write(2, "Error\n", 6);
	exit(1);
}


void	ft_cpystack(t_stack *src, t_stack *dst)
{
	dst->index = src->index;
	dst->value = src->value;
}
