#include "bsq.h"

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