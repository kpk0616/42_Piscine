/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:44:22 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/21 22:22:54 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		parse_file_first(char *buf, t_data *dat, int size)
{
	int		i;

	if (size < 5)
		return (0);
	size -= 2;
	(*dat).fill = buf[size];
	if (((*dat).full = buf[size - 1]) == (*dat).fill)
		return (0);
	if (((*dat).empt = buf[size - 2]) == (*dat).fill ||
		(*dat).empt == (*dat).fill)
		return (0);
	i = -1;
	while (++i < size - 2)
	{
		if (buf[i] >= '0' && buf[i] <= '9')
			(*dat).row = (*dat).row * 10 + (buf[i] - '0');
		else
			return (0);
	}
	return (1);
}

int		init(t_parsing *v, t_data *dat, char *filepath)
{
	(*v).bufs = 0;
	(*v).file = -1;
	if (filepath == 0)
		(*v).file = 0;
	if ((*v).file == 0 || ((*v).file = open(filepath, O_RDWR)) != -1)
	{
		(*v).state = 0;
		(*v).bufsize = __BUF;
		(*dat).row = 0;
		(*v).j = 0;
		return (1);
	}
	return (0);
}

int		read_buf(t_parsing *vals, char **lines, t_data *dat)
{
	(*vals).l = 0;
	(*vals).k = 0;
	while ((*vals).bufs)
	{
		(*vals).j = -1;
		while ((*(*vals).bufs).buf[++(*vals).j])
		{
			if ((*vals).state != 2 || (*vals).j >= (*vals).nt)
			{
				if (bufs_to_lines(vals, lines, dat) == 0)
					return (0);
			}
			else if ((*vals).j == 0)
			{
				if (parse_file_first((*(*vals).bufs).buf, dat, (*vals).nt) == 0)
					return (0);
				if ((lines = malloc(sizeof(char*) * ((*dat).row + 1))) == NULL)
					return (0);
			}
		}
		(*vals).bufs = (*vals).bufs->next;
	}
	(*vals).bufsize = (*dat).col;
	(*vals).state++;
	return (1);
}

int		read_top(t_parsing *v, char **lines, t_data *dat)
{
	(*v).buf[(*v).bufsize] = '\0';
	ft_list_push_back(&(*v).bufs, (*v).buf);
	(*v).i = 0;
	while ((*v).i < (*v).rs)
	{
		if ((*v).state == 0 && (*v).buf[(*v).i] == '\n' && ++(*v).state)
			(*v).nt = (*v).i + 1;
		else if ((*v).state == 1 && (*v).buf[(*v).i] == '\n')
		{
			(*dat).col = (*v).j - (*v).nt + 1;
			if (((*v).bufsize = (*dat).col - ((*v).rs - ((*v).i + 1))) < 0)
				(*v).bufsize += (*dat).col;
			(*v).state++;
		}
		else if (((*v).state == 2 && (*v).buf[(*v).i] == '\n' &&
			(*v).i == ((*v).rs - 1)) || (*v).bufsize == 0)
			read_buf(v, lines, dat);
		(*v).i++;
		(*v).j++;
	}
	return (1);
}

char	**parse_file(char *filepath, char **lines, t_data *dat, t_parsing *v)
{
	if (init(v, dat, filepath) == 1)
	{
		(*v).buf = malloc(sizeof(char) * ((*v).bufsize + 1));
		while (((*v).rs = read((*v).file, (*v).buf, (*v).bufsize)) != 0 && (*v).state != 3)
		{
			if ((*v).state != 4)
			{
				if (read_top(v, lines, dat) == 0)
				{
					ft_putstr("shit", 1);
					return (0);
				}
			}
			else
			{
				if (read_to_lines(v, lines, dat) == 0)
				{
					ft_putstr("autre", 1);
					return (0);
				}
			}
			if (((*v).buftmp = malloc(sizeof(char) * (*v).bufsize)) == NULL)
			{
				ft_putstr("fbipcaw", 1);
				return (0);
			}
			(*v).buf = (*v).buftmp;
		}
		if ((*dat).row < 2 || (*v).l != (*dat).row)
		{
			ft_putnbr((*v).state);
			// ft_putstr("beuh", 1);
			return (0);
		}
		lines[(*v).l] = 0;
	}
	else
		return (0);
	//ft_list_clear(&v.bufs);
	return (lines);
}
