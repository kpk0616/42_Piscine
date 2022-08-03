/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:08:35 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/19 10:43:17 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

void	ft_putstr(char *str, int out)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i], out);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-', 1);
		n *= -1;
	}
	if (n <= 9)
		ft_putchar(n + '0', 1);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
