/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:17:09 by epark             #+#    #+#             */
/*   Updated: 2022/06/06 23:44:33 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	bound;
	int	value;
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	value = min;
	bound = max - min;
	arr = (int *)malloc(sizeof(int) * bound);
	if (arr != NULL)
	{
		while (i < bound)
		{
			*(arr + i) = value++;
			i++;
		}
	}
	return (arr);
}
