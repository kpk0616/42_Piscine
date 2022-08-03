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
	t_plate *plate;
	t_data	dat;
//	int		**tab;

	plate = 0;
	if (parse_file(platepath, &plate, &dat) == 1)
	{

		ft_putstr(platepath, 1);
		ft_putstr(" ok", 1);
		while (plate)
		{
			if (plate->x == 1)
				ft_putchar('\n', 1);
			else
				ft_putchar(' ', 1);
			ft_putnbr(plate->val);
//			if (plate->val == 1)
//				ft_putchar(dat.full, 1);
//			else
//				ft_putchar(dat.empt, 1);
			plate = plate->next;
		}
		ft_putstr("\n\n", 1);
	}
	else
	{
		ft_list_clear(&plate);
		ft_putstr(__MSG_MAP_ERROR, 2);
		return (0);
	}
	ft_list_clear(&plate);
	return (1);
}
