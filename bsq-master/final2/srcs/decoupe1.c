#include "bsq.h"

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