/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:50:15 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/19 14:23:25 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_STRUCTS_H
# define BSQ_STRUCTS_H

typedef struct	s_plate
{
	int				x;
	int				y;
	int				val;
	struct s_plate	*prev;
	struct s_plate	*next;
}				t_plate;

typedef struct	s_data
{
	char	empt;
	char	full;
	char	fill;
	int		row;
	int		col;
}				t_data;

typedef struct	s_pos
{
	int		state;
	int		x;
	int		y;
	int		n_empt;
	int		n_full;
}				t_pos;

#endif
