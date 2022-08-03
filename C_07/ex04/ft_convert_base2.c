/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:17:19 by epark             #+#    #+#             */
/*   Updated: 2022/06/08 00:20:56 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_power(int n, int p)
{
	int	result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

int	get_len(long int nbr, int size, int is_negative)
{
	int	i;

	i = 0;
	if (is_negative == -1)
		i++;
	while (nbr > 0)
	{
		nbr /= size;
		i++;
	}
	return (i);
}

char	*ft_print(long int nbr, char *base, char *res, int is_negative)
{
	int		i;
	int		size;

	i = 0;
	size = get_len(nbr, ft_strlen(base), is_negative);
	if (is_negative == -1)
		res[0] = '-';
	if (nbr == 0)
	{
		res[0] = base[0];
		res[1] = '\0';
	}
	while (nbr > 0)
	{
		res[(size - i - 1)] = base[nbr % ft_strlen(base)];
		i++;
		nbr /= ft_strlen(base);
	}
	return (res);
}

char	*ft_putnbr_base(long long nbr, char *base, int is_negative)
{
	long long	l_nbr;
	char		*res;
	int			size;
	int			len;

	l_nbr = nbr;
	size = ft_strlen(base);
	len = get_len(l_nbr, size, is_negative);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if ((is_negative == -1 && len == 1) || (len == 0 && is_negative == 0))
	{
		res[0] = base[0];
		return (res);
	}
	return (ft_print(l_nbr, base, res, is_negative));
}
