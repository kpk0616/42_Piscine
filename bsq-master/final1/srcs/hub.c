/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:51:54 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/21 16:00:16 by rameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		new_plate(char *platepath, int i)
{
	char	**lines;
	t_data	dat;
	t_parsing vals;

	if (i != 1)
		ft_putstr("\n", 1);
	lines = 0;
	if ((lines = parse_file(platepath, lines, &dat, &vals)) != 0)
	{
		ft_putchar('a', 1);
		//ft_reso(lines, dat);
	}
	else
	{
		ft_putstr(__MSG_MAP_ERROR, 2);
		return (0);
	}
	return (1);
}
