/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 02:45:33 by epark             #+#    #+#             */
/*   Updated: 2022/06/03 02:52:35 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(char a, char b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}

int	check(char *arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (arr[j] == arr[i] || i - j == ft_abs(arr[i], arr[j]))
			return (0);
		j++;
	}
	return (1);
}

void	queens(char *arr, int i, int *count)
{
	int	value;

	value = 0;
	if (i == 10)
	{
		*count += 1;
		write(1, arr, 10);
		write(1, "\n", 1);
		return ;
	}
	while (value < 10)
	{
		arr[i] = value + '0';
		if (check(arr, i))
			queens(arr, i + 1, count);
		value++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	char	arr[10];
	int		i;

	count = 0;
	i = 0;
	while (i < 10)
		arr[i++] = '0';
	queens(arr, 0, &count);
	return (count);
}
