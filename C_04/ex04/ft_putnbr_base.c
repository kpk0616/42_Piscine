/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:14:29 by epark             #+#    #+#             */
/*   Updated: 2022/06/01 16:29:56 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int	is_valid(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len < 2)
		return (0);
	while (base[i])
	{	
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ' \
		|| (base [i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_recursive(int nbr, char *base, int base_len)
{
	long long int	l_nbr;

	l_nbr = nbr;
	if (l_nbr < 0)
	{
		write(1, "-", 1);
		l_nbr *= -1;
	}
	if (l_nbr >= base_len)
		ft_putnbr_recursive(l_nbr / base_len, base, base_len);
	if (l_nbr >= 0)
		ft_putchar(base[l_nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (is_valid(base, base_len) == 0)
		return ;
	ft_putnbr_recursive(nbr, base, base_len);
}
