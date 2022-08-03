/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:44:22 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/19 14:25:30 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	parse_file_first(char *buf, t_data *dat, int *state)
{
	if (*state == 0)
	{
		if (buf[0] >= '0' && buf[0] <= '9')
			(*dat).row = (*dat).row * 10 + (buf[0] - '0');
		else
			(*state)++;
	}
	if (*state == 1 && ++(*state))
		(*dat).empt = buf[0];
	else if (*state == 2 && ++(*state))
		(*dat).full = buf[0];
	else if (*state == 3 && ++(*state))
		(*dat).fill = buf[0];
	else if (*state == 4)
		if (buf[0] == '\n')
			(*state)++;
}

int		parse_file_plate(char *buf, t_data *dat, t_plate **plate, t_pos *pos)
{
	if ((*pos).state >= 5)
	{
		if (buf[0] == '\n')
		{
			if ((*dat).col == 0)
				(*dat).col = (*pos).x;
			else if ((*pos).x != (*dat).col)
				return (0);
			(*pos).x = 0;
			(*pos).y++;
		}
		else if (buf[0] == (*dat).empt)
		{
			(*pos).state++;
			ft_list_push_back(plate, (*pos).x, (*pos).y, 0);
		}
		else if (buf[0] == (*dat).full)
			ft_list_push_back(plate, (*pos).x, (*pos).y, 1);
		else
			return (0);
		(*pos).x++;
	}
	return (1);
}

int		parse_file(char *filepath, t_plate **plate, t_data *dat)
{
	int			file;
	t_pos		pos;
	char		buf[1];

	if ((file = open(filepath, O_RDWR)) != -1)
	{
		pos.state = 0;
		pos.x = 0;
		pos.y = 0;
		(*dat).row = 0;
		(*dat).col = 0;
		while (read(file, buf, 1) != 0)
		{
			parse_file_first(buf, dat, &pos.state);
			if (parse_file_plate(buf, dat, plate, &pos) == 0)
				return (0);
		}
		if (pos.y != (*dat).row + 1 || pos.state == 5)
			return (0);
	}
	else
		return (0);
	return (1);
}
