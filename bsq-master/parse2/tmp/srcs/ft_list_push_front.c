/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:08:25 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/18 20:09:45 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_list_push_front(t_buf **liste, char *buf)
{
	t_buf	*push;

	if (liste)
	{
		push = ft_create_elem(buf);
		if (push == NULL)
			return (0);
		push->next = *liste;
		*liste = push;
	}
	else
	{
		if ((*liste = ft_create_elem(buf)) == NULL)
			return (0);
	}
	return (1);
}
