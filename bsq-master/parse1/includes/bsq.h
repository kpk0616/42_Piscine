/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:01:07 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/19 15:38:19 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "bsq_lib.h"
# include "bsq_structs.h"

# define __MSG_MAP_ERROR "map error \n"

int		new_plate(char *platepath);

int		parse_file(char *filepath, t_plate **plate, t_data *dat);

int		ft_list_push_back(t_plate **begin_list, int x, int y, int val);
t_plate	*ft_create_elem(int x, int y, int val);
void	ft_list_clear(t_plate **plate);

void	ft_putchar(char c, int out);
void	ft_putstr(char *str, int out);
void	ft_putnbr(int nb);

#endif
