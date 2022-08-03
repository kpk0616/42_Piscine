/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:52:37 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/19 13:58:21 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_buf		*ft_create_elem(char *buf)
{
	t_buf		*created;

	created = NULL;
	created = malloc(sizeof(t_buf));
	if (created)
	{
		created->buf = buf;
		created->next = NULL;
	}
	return (created);
}
