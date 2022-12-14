/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:41:19 by epark             #+#    #+#             */
/*   Updated: 2022/05/26 14:53:25 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_c(int i)
{
	char	c1;
	char	c2;

	c1 = '0' + i / 10;
	c2 = '0' + i % 10;
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			put_c(a);
			write(1, " ", 1);
			put_c(b);
			if (a + b != 98 + 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
