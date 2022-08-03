/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:51:54 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/19 15:59:12 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		new_plate(char *platepath)
{
	char 	**lines;
	t_data	dat;

	lines = 0;
	if (parse_file(platepath, lines, &dat) == 1)
	{
		// if (matrix(&bufs, &dat) == 1)
		// {
			ft_putstr(platepath, 1);
			ft_putstr(" ok", 1);
		printf("\n\nrow: %d\ncol: %d\nempt: %c\nfull: %c\nfill: %c\n", dat.row, dat.col, dat.empt, dat.full, dat.fill);
		// }
// 		while (bufs)
// 		{
// 			if (bufs->x == 1)
// 				ft_putchar('\n', 1);
// 			else
// 				ft_putchar(' ', 1);
// 			ft_putnbr(bufs->val);
// //			if (bufs->val == 1)
// //				ft_putchar(dat.full, 1);
// //			else
// //				ft_putchar(dat.empt, 1);
// 			bufs = bufs->next;
// 		}
		ft_putstr("\n\n", 1);
	}
	else
	{
		// ft_list_clear(&bufs);
		ft_putstr(__MSG_MAP_ERROR, 2);
		return (0);
	}
	// ft_list_clear(&bufs);
	return (1);
}
