/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:44:22 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/19 18:33:24 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	parse_file_first(char buf, t_data *dat, int *state)
{
	if (*state == 0)
	{
		if (buf >= '0' && buf <= '9')
			(*dat).row = (*dat).row * 10 + (buf - '0');
		else
			(*state)++;
	}
	if (*state == 1 && ++(*state))
		(*dat).empt = buf;
	else if (*state == 2 && ++(*state))
		(*dat).full = buf;
	else if (*state == 3 && ++(*state))
		(*dat).fill = buf;
}

char	**parse_file(char *filepath, char **lines, t_data *dat)
{
	int		file;
	t_buf	*bufs;
	int 	bufsize = __BUF;
	char	*buf;
	char	*buftmp;
	int		readen;
	int		i;
	int		j;
	int		k;
	int		l;
	int		nt;
	int		state = 0;

	bufs = 0;
	if ((file = open(filepath, O_RDWR)) != -1)
	{

		(*dat).row = 0;
		buf = malloc(sizeof(char) * (bufsize + 1));
		j = 0;
		while ((readen = read(file, buf, bufsize)) != 0 && state != 7)
		{
			if (readen != bufsize)
			{
				ft_putstr("end file\n", 1);
				ft_putnbr(state);
				ft_putchar('\n', 1);
			}
			if (state != 8)
			{
				buf[bufsize] = '\0';
				ft_list_push_back(&bufs, buf);
				i = 0;
				while (i < readen)
				{
					parse_file_first(buf[i], dat, &state);
					if (state == 4 && buf[i] == '\n')
					{
						nt = i + 1;
						state++;
					}
					else if (state == 5 && buf[i] == '\n')
					{
						(*dat).col = j - nt + 1;
						if ((bufsize = (*dat).col - (readen - (i + 1))) < 0)
							bufsize += (*dat).col;
						ft_putnbr(bufsize);
						ft_putstr("\n\n", 1);
						state++;
					}
					else if ((state == 6 && buf[i] == '\n') || bufsize == 0)
					{
						lines = malloc(sizeof(char*) * ((*dat).row + 1));
						l = 0;
						k = 0;
						while (bufs)
						{
							j = -1;
							while ((*bufs).buf[++j])
							{
								if (state != 6 || j >= nt)
								{
									if (k == 0)
									{
										lines[l] = malloc(sizeof(char) * (*dat).col);
									}
									if ((*bufs).buf[j] == '\n')
									{
										lines[l][k] = '\0';
										k = 0;
										l++;
									}
									else
										lines[l][k++] = (*bufs).buf[j];
									if (state == 6 && j >= nt)
										state++;
								}
								else
								{
									ft_putchar((*bufs).buf[j], 1);
								}
							}
							bufs = bufs->next;
						}
						ft_list_clear(&bufs);
						bufsize = (*dat).col;
						ft_putstr("\n\n", 1);
						ft_putnbr(bufsize);
						state++;
					}
					i++;
					j++;
				}
			}
			else
			{
				lines[l] = malloc(sizeof(char) * (*dat).col);
				lines[l] = buf;
				if (lines[l][(*dat).col - 1] == '\n')
					lines[l++][(*dat).col - 1] = '\0';
				else
					return (0);
			}
			buftmp = malloc(sizeof(char) * bufsize);
			buf = buftmp;
		}
		lines[l] = 0;
	}
	return (lines);
}
