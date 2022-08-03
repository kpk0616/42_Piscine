/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:59:27 by epark             #+#    #+#             */
/*   Updated: 2022/06/02 02:46:54 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	sort(int ac, char **av)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	if (ac >= 1)
	{
		while (++i < ac)
		{
			j = i;
			while (++j < ac)
			{
				if (ft_strcmp(av[i], av[j]) > 0)
				{
					temp = av[i];
					av[i] = av[j];
					av[j] = temp;
				}
			}
		}
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	sort(ac, av);
	while (i++ < ac - 1)
	{
		ft_putstr(av[i]);
		write(1, "\n", 1);
	}
	return (0);
}
