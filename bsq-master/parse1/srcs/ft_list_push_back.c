/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:17:46 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/19 13:56:49 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_list_push_back(t_plate **begin_list, int x, int y, int val)
{
	t_plate		*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(x, y, val);
		list->next->prev = list;
	}
	else
		*begin_list = ft_create_elem(x, y, val);
	return (1);
}
