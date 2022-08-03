/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekkang <jaekkang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:15:19 by jaekkang          #+#    #+#             */
/*   Updated: 2022/05/22 16:41:30 by jaekkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_print(int inputx)
{
	int	x;

	x = 1;
	while (x <= inputx)
	{
		if (x == 1)
			ft_putchar('/');
		else if (x == inputx)
			ft_putchar('\\');
		else
			ft_putchar('*');
		x++;
	}
	ft_putchar('\n');
}

void	end_print(int inputx)
{
	int	x;

	x = 1;
	while (x <= inputx)
	{
		if (x == 1)
			ft_putchar('\\');
		else if (x == inputx)
			ft_putchar('/');
		else
			ft_putchar('*');
		x++;
	}
	ft_putchar('\n');
}

void	middle_print(int inputx)
{
	int	x;

	x = 1;
	while (x <= inputx)
	{
		if (x == 1 || x == inputx)
			ft_putchar('*');
		else
			ft_putchar(' ');
		x++;
	}
	ft_putchar('\n');
}

void	rush(int inputx, int inputy)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y <= inputy)
	{
		if (y == 1)
			first_print(inputx);
		else if (y == inputy)
			end_print(inputx);
		else
			middle_print(inputx);
		y++;
	}
}
