/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:56:24 by epark             #+#    #+#             */
/*   Updated: 2022/06/01 17:08:53 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	existent(char *base, char c)
{
	int	index;

	index = 0;
	while (*(base + index))
	{
		if (*(base + index) == c)
			return (index);
		index++;
	}
	return (-1);
}

int	make_result(char *str, char *base, int base_len)
{
	int	res;
	int	index;

	res = 0;
	while (1)
	{
		index = existent(base, *str++);
		if (index == -1)
			break ;
		res *= base_len;
		res += index;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	base_len = ft_strlen(base);
	if (is_valid(base, base_len) == 0)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = make_result(str, base, base_len);
	return (res * sign);
}
