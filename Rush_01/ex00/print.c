/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:19:17 by epark             #+#    #+#             */
/*   Updated: 2022/05/29 21:36:26 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

void	output(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(tab[i][j]);
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	error_check(char *str, int *tab, int *errortag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 1)
		{
			if (str[i] != ' ')
				*errortag = 1;
		}
		else if (i % 2 == 0)
		{
			if (str[i] >= '0' && str[i] <= '4')
				tab[j++] = ft_atoi(str + i);
			else
				*errortag = 1;
		}
		i++;
	}
}

int	*catch_num(char *str, int *tab)
{
	int	errortag;

	errortag = 0;
	if (tab == 0)
		return (0);
	error_check(str, tab, &errortag);
	if (errortag)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (tab);
}

int	check_num(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ft_strlen(argv[1]) != 31)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}
