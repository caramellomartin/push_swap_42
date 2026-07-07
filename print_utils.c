#include "push_swap.h"

void	ft_putstr_err(char *str)
{
	if (!str)
		return ;
	write(2, str, ft_strlen(str));
}

void	ft_putnbr_err(int n)
{
	char	c;
	long	num;

	num = n;
	if (num < 0)
	{
		write(2, "-", 1);
		num = -num;
	}
	if (num > 9)
		ft_putnbr_err(num / 10);
	c = (num % 10) + '0';
	write(2, &c, 1);
}

void	ft_putfloat_err(double disorder)
{
	int	integer_part;
	int	decimal_part;

	disorder = disorder * 100.0;
	integer_part = (int)disorder;
	decimal_part = (int)((disorder - integer_part) * 100.5);
	ft_putnbr_err(integer_part);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	ft_putnbr_err(decimal_part);
	write(2, "%\n", 2);
}
