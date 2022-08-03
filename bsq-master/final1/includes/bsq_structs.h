/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:50:15 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/21 17:43:24 by rameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_STRUCTS_H
# define BSQ_STRUCTS_H

typedef struct	s_buf
{
	char			*buf;
	struct s_buf	*next;
}				t_buf;

typedef struct	s_data
{
	char	empt;
	char	full;
	char	fill;
	int		row;
	int		col;
}				t_data;

typedef struct	s_carre
{
	int		i;
	int		j;
	int		maxi;
	int		maxj;
}				t_carre;

typedef struct	s_reso
{
	int i;
	int j;
	int vmax;
	int to_jump;
	int n;
}				t_reso;

typedef struct	s_parsing
{
	int		file;
	t_buf	*bufs;
	int		bufsize;
	char	*buf;
	char	*buftmp;
	int		rs;
	int		i;
	int		j;
	int		k;
	int		l;
	int		nt;
	int		state;
}				t_parsing;
#endif
