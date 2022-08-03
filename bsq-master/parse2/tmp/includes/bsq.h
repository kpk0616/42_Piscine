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
# define __BUF 8192
# define __MBUF 15

int		new_plate(char *platepath);

int		parse_file(char *filepath, char **lines, t_data *dat);

int		ft_list_push_back(t_buf **liste, char *buf);
t_buf	*ft_create_elem(char *buf);
void	ft_list_clear(t_buf **plate);

void	ft_putchar(char c, int out);
void	ft_putstr(char *str, int out);
void	ft_putstr_buf(char *buf);
void	ft_putnbr(int nb);

#endif
