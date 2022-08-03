/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 21:01:30 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/21 21:01:31 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		bufs_to_lines(t_parsing *v, char **lines, t_data *dat)
{
	if ((*v).k == 0)
		if ((lines[(*v).l] = malloc((*dat).col + 1)) == NULL)
			return (0);
	if ((*(*v).bufs).buf[(*v).j] == '\n')
	{
		if ((*v).k != (*dat).col - 1)
			return (0);
		lines[(*v).l][(*v).k] = '\0';
		(*v).k = 0;
		(v->l)++;
	}
	else
		lines[(*v).l][(*v).k++] = (*(*v).bufs).buf[(*v).j];
	if ((*v).state == 2)
		(*v).state++;
	return (1);
}

int		read_to_lines(t_parsing *vals, char **lines, t_data *dat)
{
	if ((*vals).l >= (*dat).row)
		return (0);
	if ((lines[(*vals).l] = malloc(sizeof(char) * ((*dat).col + 2))) == NULL)
		return (0);
	lines[(*vals).l] = (*vals).buf;
	if (lines[(*vals).l][(*dat).col - 1] == '\n')
		lines[(*vals).l++][(*dat).col - 1] = '\0';
	else
		return (0);
	return (1);
}
