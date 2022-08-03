/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:19:13 by epark             #+#    #+#             */
/*   Updated: 2022/05/29 21:42:32 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		overlap(int board[4][4], int index, int num);
int		leftrow_check(int board[4][4], int index, int str[16]);
int		rightrow_check(int board[4][4], int index, int str[16]);
int		upcol_check(int board[4][4], int index, int str[16]);
int		downcol_check(int board[4][4], int index, int str[16]);
int		*catch_num(char *str, int *tab);
int		check_num(int argc, char **argv);
void	output(int tab[4][4]);
void	ft_putstr(char *str);

int	input(int board[4][4], int index, int str[16])
{
	int	num;

	num = 1;
	if (index == 16)
		return (1);
	while (num <= 4)
	{
		if (!overlap(board, index, num))
		{	
			board[index / 4][index % 4] = num;
			if (upcol_check(board, index, str) && \
			downcol_check(board, index, str) \
			&& leftrow_check(board, index, str) \
			&& rightrow_check(board, index, str))
				if (input(board, index + 1, str) == 1)
					return (1);
		}
		num++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	board[4][4];
	int	*array;
	int	i;
	int	j;
	int	*tab;

	tab = (int *)malloc(sizeof(int) * 16);
	i = 0;
	j = 0;
	while (i++ < 4)
		while (j++ < 4)
			board[i][j] = 0;
	if (check_num(argc, argv) == 0)
		return (0);
	array = catch_num(argv[1], tab);
	if (array != 0)
	{
		if (input(board, 0, array) == 1)
			output(board);
		else
			ft_putstr("Error\n");
	}
	free(tab);
	return (0);
}
