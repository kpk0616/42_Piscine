/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:51:54 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/20 14:59:20 by rameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		new_plate(char *platepath)
{
	char	**lines;
	t_data	dat;
	int		a;

	lines = 0;
	if ((lines = parse_file(platepath, lines, &dat)) != 0)
		a = 1;
		// ft_reso_bien(lines, dat);
	else
	{
		ft_putstr(__MSG_MAP_ERROR, 2);
		return (0);
	}
	return (1);
}
