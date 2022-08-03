/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:18:58 by epark             #+#    #+#             */
/*   Updated: 2022/05/29 21:06:12 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	overlap(int board[4][4], int index, int num)
{	
	int	i;

	i = 0;
	while (i < (index % 4))
	{	
		if (board[index / 4][i] == num)
			return (1);
			i++;
	}
	i = 0;
	while (i < (index / 4))
	{
		if (board[i][index % 4] == num)
			return (1);
			i++;
	}	
	return (0);
}

int	leftrow_check(int board[4][4], int index, int str[16])
{
	int	i;
	int	value;
	int	cnt;

	i = 0;
	value = 0;
	cnt = 0;
	if (index % 4 == 3)
	{
		while (i < 4)
		{
			if (board[index / 4][i] > value)
			{
				value = board[index / 4][i];
				cnt++;
			}
			i++;
		}
		if (str[8 + (index / 4)] == cnt)
			return (1);
		else
			return (0);
	}
	return (1);
}

int	rightrow_check(int board[4][4], int index, int str[16])
{
	int	i;
	int	value;
	int	cnt;

	i = 3;
	value = 0;
	cnt = 0;
	if (index % 4 == 3)
	{
		while (i >= 0)
		{
			if (board[index / 4][i] > value)
			{
				value = board[index / 4][i];
				cnt ++;
			}
			i--;
		}
		if (str[12 + (index / 4)] == cnt)
			return (1);
		else
			return (0);
	}
	return (1);
}

int	upcol_check(int board[4][4], int index, int str[16])
{
	int	i;
	int	value;
	int	cnt;

	i = 0;
	value = 0;
	cnt = 0;
	if (index / 4 == 3)
	{
		while (i < 4)
		{
			if (board[i][index % 4] > value)
			{
				value = board[i][index % 4];
				cnt++;
			}
			i++;
		}
		if (str[index % 4] == cnt)
			return (1);
		else
			return (0);
	}
	return (1);
}

int	downcol_check(int board[4][4], int index, int str[16])
{
	int	i;
	int	value;
	int	cnt;

	i = 3;
	value = 0;
	cnt = 0;
	if (index / 4 == 3)
	{
		while (i >= 0)
		{
			if (board[i][index % 4] > value)
			{
				value = board[i][index % 4];
				cnt ++;
			}
			i--;
		}
		if (str[4 + index % 4] == cnt)
			return (1);
		else
			return (0);
	}
	return (1);
}
