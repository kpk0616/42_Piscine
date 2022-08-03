/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:16:07 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/22 18:24:38 by donghki2         ###   ########.fr       */
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
			ft_putchar('A');
		else if (x == inputx)
			ft_putchar('C');
		else
			ft_putchar('B');
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
			ft_putchar('C');
		else if (x == inputx)
			ft_putchar('A');
		else
			ft_putchar('B');
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
			ft_putchar('B');
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
