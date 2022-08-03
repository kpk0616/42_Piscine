/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:50:15 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/20 14:17:20 by ybayart          ###   ########.fr       */
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
#endif
