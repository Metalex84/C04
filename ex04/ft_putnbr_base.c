/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:12:25 by alejango          #+#    #+#             */
/*   Updated: 2023/08/22 14:36:48 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] < 32 || base[i] > 126 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (base[0] && base[1]);
}

int	ft_handle_number(int *nbr)
{
	if (*nbr == -2147483648)
	{
		ft_putchar('-');
		return (0);
	}
	if (*nbr < 0)
	{
		ft_putchar('-');
		*nbr *= -1;
	}
	return (1);
}

void	ft_print_extreme(void)
{
	int	i;

	ft_putchar('8');
	i = 0;
	while (i < 7)
	{
		ft_putchar('0');
		i += 1;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	i;
	int	resultado[256];

	if (ft_check(base))
	{
		if (ft_handle_number(&nbr))
		{
			size = 0;
			while (base[size])
				size += 1;
			i = 0;
			while (nbr)
			{
				resultado[i++] = nbr % size;
				nbr /= size;
			}
			while (--i >= 0)
				ft_putchar(base[resultado[i]]);
		}
		else
			ft_print_extreme();
	}
}
