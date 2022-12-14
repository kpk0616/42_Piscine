/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:55:53 by epark             #+#    #+#             */
/*   Updated: 2022/05/21 00:40:44 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	arr[3];

	arr[0] = '0';
	arr[1] = '1';
	arr[2] = '2';
	while (arr[0] <= '7')
	{
		while (arr[1] <= '8')
		{
			while (arr[2] <= '9')
			{
				write(1, arr, 3);
				if (!(arr[0] == '7' && arr[1] == '8' && arr[2] == '9'))
					write(1, ", ", 2);
				arr[2]++;
			}
			arr[1]++;
			arr[2] = arr[1] + 1;
		}
		arr[0]++;
		arr[1] = arr[0] + 1;
		arr[2] = arr[1] + 1;
	}
}
