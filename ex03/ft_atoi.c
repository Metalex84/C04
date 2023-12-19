/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:24:45 by alejango          #+#    #+#             */
/*   Updated: 2023/08/22 15:07:03 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_is_symbol(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	numero;
	int	signo;

	numero = 0;
	signo = 1;
	while (ft_is_space(*str))
		str++;
	while (ft_is_symbol(*str))
	{
		if (*str == '-')
			signo *= -1;
		str++;
	}
	while (ft_is_number(*str))
	{
		numero = numero * 10 + (*str - '0');
		str++;
	}
	return (signo * numero);
}
