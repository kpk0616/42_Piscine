/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:18:11 by rameur            #+#    #+#             */
/*   Updated: 2019/08/20 15:19:17 by rameur           ###   ########.fr       */
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
		while (j < 15)
		{
			ft_putchar(lines[i][j], 1);
			ft_putstr(" ", 1);
			j++;
		}
		ft_putstr("\n", 1);
		j = 0;
		i++;
	}
}

int 	check_ligne(char **lines, int i, int j, t_data dat)
{
	while (j >= 0)
	{
		if (lines[i][j] == dat.full)
			return (1);
		j--;
	}
	return (0);
}

int		check_col(char **lines,int i, int j, t_data dat)
{
	while (i >= 0)
	{
		if (lines[i][j] == dat.full)
			return (1);
		i--;
	}
	return (0);
}

void	display_test(t_carre carre, int i, int j)
{
	printf("\nij = %d %d\n", i, j);
//	printf("carre.i = %d\n", carre.i);
//	printf("carre.j = %d\n", carre.j);
	printf("carre.maxi = %d\n", carre.maxi);
//	printf("carre.maxj = %d\n", carre.maxj);
}

int		ft_carre(char **lines, int i, int j, t_data dat)
{

	int n;

	n = 0;
	while (lines[i + n][j + n] == dat.empt &&
			check_ligne(lines, i + n, j + n, dat) == 0 &&
			check_col(lines, i + n, j + n, dat) == 0)
	{
		//printf("\ni + n et j  + n= %d %d\n", i + n, j + n);	
		n++;
	}
	printf("n = %d\n", n);
	return (n);
}

void	ft_reso_bien(char **lines, t_data dat)
{
	int i;
	int j;
	int vmax;
	t_carre carre;

	i = 0;
	vmax = 0;
	carre.maxi = 0;
	carre.maxj = 0;
	while (i < dat.row - 1)
	{
		j = 0;
		ft_display(lines, dat);
		while (lines[i][j])
		{
			display_test(carre, i, j);
			if ((vmax = ft_carre(lines,i, j, dat)) > carre.maxi)
			{
				carre.i = i;
				carre.j = j;
				carre.maxi = i + vmax;
				carre.maxj = j + vmax;
			}
				j++;
		}
		i++;
	}
	ft_rempli(lines, carre, dat);
}

void	ft_rempli(char **lines, t_carre carre, t_data dat)
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
	ft_putstr("\n", 1);
	ft_display(lines, dat);
}
