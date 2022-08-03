/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:51:54 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/21 21:12:03 by rameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		new_plate(char *platepath, int i)
{
	char		**lines;
	t_data		dat;

	if (i != 1)
		ft_putstr("\n", 1);
	if ((lines = parse_file(platepath, &dat)) != 0)
	{
		ft_reso(lines, dat);
	}
	else
	{
		ft_putstr(__MSG_MAP_ERROR, 2);
		return (0);
	}
	return (1);
}
