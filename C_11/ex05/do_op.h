/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:13:58 by epark             #+#    #+#             */
/*   Updated: 2022/06/09 11:14:00 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include "unistd.h"

int		sum(int x, int y);
int		sub(int x, int y);
int		mul(int x, int y);
int		div(int x, int y);
int		mod(int x, int y);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

#endif
