/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:14:05 by epark             #+#    #+#             */
/*   Updated: 2022/06/09 11:14:06 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

char	g_op_index[5];
char	*g_err_msg[2];

void	init(int (*fcal[5])(int, int))
{
	g_op_index[0] = '/';
	g_op_index[1] = '%';
	g_op_index[2] = '*';
	g_op_index[3] = '-';
	g_op_index[4] = '+';
	fcal[0] = div;
	fcal[1] = mod;
	fcal[2] = mul;
	fcal[3] = sub;
	fcal[4] = sum;
	g_err_msg[0] = "Stop : division by zero";
	g_err_msg[1] = "Stop : modulo by zero";
}

int	is_valid_op(char c)
{
	if (c == '+' || c == '-' || c == '*')
		return (1);
	else if (c == '/' || c == '%')
		return (1);
	return (0);
}

int	find_idx(char op)
{
	int	idx;

	idx = 0;
	while (is_valid_op(op))
	{
		if (g_op_index[idx] == op)
			return (idx);
		idx++;
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	char	op;
	int		val1;
	int		val2;
	int		(*fcal[5])(int, int);

	init(fcal);
	if (argc != 4)
		return (0);
	op = argv[2][0];
	if (argv[2][1] || !is_valid_op(op))
	{
		ft_putstr("0\n");
		return (0);
	}
	val1 = ft_atoi(argv[1]);
	val2 = ft_atoi(argv[3]);
	if (val2 == 0 && (op == '/' || op == '%'))
		ft_putstr(g_err_msg[find_idx(op)]);
	else
		ft_putnbr(fcal[find_idx(op)](val1, val2));
	ft_putstr("\n");
	return (0);
}
