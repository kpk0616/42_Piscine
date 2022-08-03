/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:01:07 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/21 21:45:41 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "bsq_lib.h"
# include "bsq_structs.h"

# define __MSG_MAP_ERROR "map error \n"
# define __BUF 4

int		new_plate(char *platepath, int i);

char	**parse_file(char *filepath, char **lines, t_data *dat, t_parsing *v);

int		ft_list_push_back(t_buf **liste, char *buf);
t_buf	*ft_create_elem(char *buf);
void	ft_list_clear(t_buf **plate);
int		bufs_to_lines(t_parsing *v, char **lines, t_data *dat);
int		read_to_lines(t_parsing *vals, char **lines, t_data *dat);

void	ft_matrix(char **lines);
void	ft_display(char **lines, t_data dat);
void	ft_reso(char **lines, t_data dat);
void	ft_reso_2(char **lines, t_data dat, t_reso *all, t_carre *carre);
void	ft_fill(char **lines, t_carre carre, t_data dqat);
int		check_ligne(char **lines, t_reso all, t_data dat);
int		check_col(char **lines, t_reso all, t_data dat);
int		square_is_sup(t_carre carre, int vmax);
int		ft_square(char **lines, t_reso all, t_data dat, int *to_jump);
void	free_matrice(char **lines, t_data dat);

void	ft_putchar(char c, int out);
void	ft_putstr(char *str, int out);
void	ft_putstr_buf(char *buf);
void	ft_putnbr(int nb);

#endif
