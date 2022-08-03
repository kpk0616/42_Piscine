/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:56:24 by epark             #+#    #+#             */
/*   Updated: 2022/06/07 23:47:58 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_power(int n, int p);
char	*ft_putnbr_base(int nbr, char *base, int is_negative);

int	is_valid(char *base)
{
	int	i;
	int	j;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
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

char	*check_sign(char *str, int *is_negative)
{
	*is_negative = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*is_negative *= -1;
		str++;
	}
	return (str);
}

char	*ft_atoi(char *str, char *base, int *is_negative, int *size)
{
	int	i;
	int	j;
	int	valid;

	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	str = check_sign(str, is_negative);
	while (*str)
	{
		j = -1;
		valid = 0;
		while (base[++j])
			if (*str == base[j])
				valid = 1;
		if (valid == 0)
			break ;
		str++;
		i++;
	}
	*size = i;
	return (str - i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	l_nbr;
	int			is_negative;
	int			size;
	int			i;
	int			n;

	l_nbr = 0;
	i = 0;
	nbr = ft_atoi(nbr, base_from, &is_negative, &size);
	if (is_valid(base_from) == 0 || is_valid(base_to) == 0)
		return (NULL);
	while (i < size)
	{
		n = 0;
		while (base_from[n] != nbr[i])
			n++;
		l_nbr += n * ft_power(ft_strlen(base_from), (size - i - 1));
		i++;
	}
	return (ft_putnbr_base(l_nbr, base_to, is_negative));
}
