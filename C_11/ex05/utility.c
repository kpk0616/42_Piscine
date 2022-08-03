/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:14:17 by epark             #+#    #+#             */
/*   Updated: 2022/06/09 11:14:18 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	rec_putnbr(int nb)
{
	char	c;

	if (nb == 0)
		return ;
	c = '0' + nb % 10;
	rec_putnbr(nb / 10);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		c = '0' - nb % 10;
		rec_putnbr(-(nb / 10));
	}
	else
	{
		c = '0' + nb % 10;
		rec_putnbr(nb / 10);
	}
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= sign;
	return (num);
}
