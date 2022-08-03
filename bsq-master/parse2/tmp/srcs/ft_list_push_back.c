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

int		ft_list_push_back(t_buf **liste, char *buf)
{
	t_buf		*list;

	list = *liste;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(buf);
	}
	else
		*liste = ft_create_elem(buf);
	return (1);
}
