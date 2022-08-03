/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:44:22 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/21 16:50:23 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_parsing	g_v;
char		**g_l;

int		dec1(char *filepath, t_data *dat)
{
	g_v.file = -1;
	if (filepath == 0)
		g_v.file = 0;
	if (g_v.file == 0 || (g_v.file = open(filepath, O_RDWR)) != -1)
	{
		g_v.bufsize = __MBUF;
		g_v.state = 0;
		(*dat).row = 0;
		g_v.buf = malloc(sizeof(char) * (g_v.bufsize + 1));
		g_v.j = 0;
		return (1);
	}
	return (0);
}

int		parse_file_first(char *buf, t_data *dat)
{
	int		i;
	int		size;

	size = g_v.nt;
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

int		dec2(t_data *dat, t_buf *bufs)
{
	if (g_v.k == 0)
		if ((g_l[g_v.l] = malloc(sizeof(char) * ((*dat).col + 2))) == NULL)
			return (0);
	if ((*bufs).buf[g_v.j] == '\n')
	{
		if (g_v.k != (*dat).col - 1)
			return (0);
		g_l[g_v.l][g_v.k] = '\0';
		g_v.k = 0;
		g_v.l++;
	}
	else
		g_l[g_v.l][g_v.k++] = (*bufs).buf[g_v.j];
	if (g_v.state == 2)
		g_v.state++;
	return (1);
}

int		read_to_g_l(t_data *dat)
{
	if (g_v.l >= (*dat).row)
		return (0);
	if ((g_l[g_v.l] = malloc(sizeof(char) * ((*dat).col + 2))) == NULL)
		return (0);
	g_l[g_v.l] = g_v.buf;
	if (g_l[g_v.l][(*dat).col - 1] == '\n')
		g_l[g_v.l++][(*dat).col - 1] = '\0';
	else
		return (0);
	return (1);
}

void	dec4(void)
{
	g_v.nt = g_v.i + 1;
	g_v.state++;
}

void	dec5(t_data *dat)
{
	(*dat).col = g_v.j - g_v.nt + 1;
	if ((g_v.bufsize = (*dat).col - (g_v.readen - (g_v.i + 1))) < 0)
		g_v.bufsize += (*dat).col;
	g_v.state++;
}

void	dec6(t_buf ***bufs)
{
	g_v.buf[g_v.bufsize] = '\0';
	ft_list_push_back(*bufs, g_v.buf);
	g_v.i = 0;
}

void	dec7(void)
{
	g_v.l = 0;
	g_v.k = 0;
}

void	dec8(t_data *dat)
{
	g_v.bufsize = (*dat).col;
	g_v.state++;
}

int		dec9(t_buf ***bufs, t_data *dat)
{
	g_v.j = -1;
	while ((***bufs).buf[++g_v.j])
	{
		if (g_v.state != 2 || g_v.j >= g_v.nt)
			dec2(dat, **bufs);
		else if (g_v.j == 0)
		{
			if (parse_file_first((***bufs).buf, dat) == 0)
				return (0);
			g_l = malloc(sizeof(char*) * ((*dat).row + 1));
		}
	}
	**bufs = (**bufs)->next;
	return (1);
}

void	dec10(t_buf **bufs, t_data *dat)
{
	dec6(&bufs);
	while (g_v.i < g_v.readen)
	{
		if (g_v.state == 0 && g_v.buf[g_v.i] == '\n')
			dec4();
		else if (g_v.state == 1 && g_v.buf[g_v.i] == '\n')
			dec5(dat);
		else if ((g_v.state == 2 && g_v.buf[g_v.i] == '\n'
			&& g_v.i == (g_v.readen - 1)) || g_v.bufsize == 0)
		{
			dec7();
			while (*bufs)
				dec9(&bufs, dat);
			dec8(dat);
		}
		g_v.i++;
		g_v.j++;
	}
}

char	**parse_file(char *filepath, t_data *dat)
{
	t_buf	*bufs;

	bufs = 0;
	if (dec1(filepath, dat) == 1)
	{
		while ((g_v.readen = read(g_v.file, g_v.buf, g_v.bufsize)) != 0
			&& g_v.state != 3)
		{
			if (g_v.state != 4)
			{
				dec10(&bufs, dat);
			}
			else
			{
				if (read_to_g_l(dat) == 0)
					return (0);
			}
			g_v.buftmp = malloc(sizeof(char) * g_v.bufsize);
			g_v.buf = g_v.buftmp;
		}
		if ((*dat).row < 2 || g_v.l != (*dat).row)
			return (0);
		g_l[g_v.l] = 0;
	}
	return (g_l);
}
