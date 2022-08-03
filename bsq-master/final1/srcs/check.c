/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:06:05 by rameur            #+#    #+#             */
/*   Updated: 2019/08/21 17:49:16 by rameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check_ligne(char **lines, t_reso all, t_data dat)
{
	all.i += all.n;
	all.j += all.n;
	while (all.j >= 0 && all.n >= 0)
	{
		if (lines[all.i][all.j] == dat.full)
			return (1);
		all.j--;
		all.n--;
	}
	return (0);
}

int		check_col(char **lines, t_reso all, t_data dat)
{
	all.i += all.n;
	all.j += all.n;
	while (all.i >= 0 && all.n >= 0)
	{
		if (lines[all.i][all.j] == dat.full)
			return (1);
		all.i--;
		all.n--;
	}
	return (0);
}

int		square_is_sup(t_carre carre, int vmax)
{
	if (vmax > (carre.maxi - carre.i))
		return (1);
	return (0);
}

int		ft_square(char **lines, t_reso all, t_data dat, int *to_jump)
{
	int	iscol;

	all.n = 0;
	iscol = 0;
	while (all.i + all.n < (dat.row) && all.j + all.n < dat.col &&
			lines[all.i + all.n][all.j + all.n] == dat.empt &&
			check_ligne(lines, all, dat) == 0 &&
			(iscol = check_col(lines, all, dat)) == 0)
	{
		all.n++;
	}
	if (iscol == 1)
		*to_jump = all.n;
	return (all.n);
}
