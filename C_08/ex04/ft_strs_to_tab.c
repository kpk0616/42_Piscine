/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:57:18 by epark             #+#    #+#             */
/*   Updated: 2022/06/05 16:39:13 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *src)
{
	int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = str_len(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr != 0)
	{
		while (*(src + i))
		{
			*(ptr + i) = *(src + i);
			i++;
		}
		*(ptr + i) = '\0';
	}
	return (ptr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*obj;
	int			i;

	i = 0;
	obj = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (obj == 0)
		return (0);
	while (i < ac)
	{
		obj[i].size = str_len(av[i]);
		obj[i].str = av[i];
		obj[i].copy = ft_strdup(av[i]);
		i++;
	}
	obj[i].str = 0;
	return (obj);
}
