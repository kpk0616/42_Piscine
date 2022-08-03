/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:52:31 by epark             #+#    #+#             */
/*   Updated: 2022/05/22 18:22:41 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_and_end_print(int inputx, int inputy)
{
	int	x;

	x = 1;
	while (x <= inputx)
	{
		if (x == 1 || x == inputx)
		{
			if (inputy == 1)
				ft_putchar('A');
			else
				ft_putchar('C');
		}
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
		if (y == 1 || y == inputy)
			first_and_end_print(inputx, y);
		else
			middle_print(inputx);
		y++;
	}
}
