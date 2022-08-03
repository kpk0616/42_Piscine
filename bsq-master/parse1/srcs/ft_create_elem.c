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

t_plate		*ft_create_elem(int x, int y, int val)
{
	t_plate		*created;

	created = NULL;
	created = malloc(sizeof(t_plate));
	if (created)
	{
		created->x = x;
		created->y = y;
		created->val = val;
		created->next = NULL;
		created->prev = NULL;
	}
	return (created);
}
