/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:13:47 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/22 18:14:01 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_and_end_print(int inputx)
{
	int	x;

	x = 1;
	while (x <= inputx)
	{
		if (x == 1 || x == inputx)
			ft_putchar('o');
		else
			ft_putchar('-');
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
			ft_putchar('|');
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
			first_and_end_print(inputx);
		else
			middle_print(inputx);
		y++;
	}
}
