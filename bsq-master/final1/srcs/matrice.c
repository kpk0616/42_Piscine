/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:18:11 by rameur            #+#    #+#             */
/*   Updated: 2019/08/21 20:19:25 by rameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_display(char **lines, t_data dat)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < dat.row)
	{
		write(1, lines[i], dat.col);
		ft_putstr("\n", 1);
		j = 0;
		i++;
	}
}

void	ft_reso_2(char **lines, t_data dat, t_reso *all, t_carre *carre)
{
	while (all->j < dat.col - 1)
	{
		if (all->to_jump > 0)
			all->to_jump--;
		else if (square_is_sup(*carre, all->vmax =
					ft_square(lines, *all, dat, &all->to_jump)) == 1)
		{
			carre->i = all->i;
			carre->j = all->j;
			carre->maxi = all->i + all->vmax;
			carre->maxj = all->j + all->vmax;
		}
		if (lines[all->i][all->j] != dat.empt &&
			lines[all->i][all->j] != dat.full)
		{
			ft_putstr(__MSG_MAP_ERROR, 2);
			free_matrice(lines, dat);
			exit(0);
		}
		all->j++;
	}
}

void	ft_init_struct(t_reso *all, t_carre *carre)
{
	all->i = 0;
	all->j = 0;
	all->to_jump = 0;
	all->vmax = 0;
	carre->i = 0;
	carre->j = 0;
	carre->maxi = 0;
	carre->maxj = 0;
}

void	ft_reso(char **lines, t_data dat)
{
	t_reso	all;
	t_carre carre;

	ft_init_struct(&all, &carre);
	while (all.i < dat.row)
	{
		all.j = 0;
		ft_reso_2(lines, dat, &all, &carre);
		all.i++;
	}
	all.j = all.i;
	ft_fill(lines, carre, dat);
}

void	ft_fill(char **lines, t_carre carre, t_data dat)
{
	int j;

	j = carre.j;
	while (carre.i < carre.maxi)
	{
		while (carre.j < carre.maxj)
		{
			lines[carre.i][carre.j] = dat.fill;
			carre.j++;
		}
		carre.j = j;
		carre.i++;
	}
	ft_display(lines, dat);
	free_matrice(lines, dat);
}
