/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:40:18 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/19 15:51:10 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_matrice(char **lines, t_data dat)
{
	int sup;

	sup = 0;
	while (sup++ < dat.row)
		free(lines[sup]);
	free(lines);
}

void	ft_list_clear(t_buf **bufs)
{
	t_buf	*ptr;
	t_buf	*list;

	list = *bufs;
	if (list)
		while (list)
		{
			ptr = list->next;
			free(list);
			list = ptr;
		}
}
