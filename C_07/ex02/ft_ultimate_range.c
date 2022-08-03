/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:17:12 by epark             #+#    #+#             */
/*   Updated: 2022/06/07 19:32:41 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	bound;
	int	i;

	if (min >= max)
	{	
		*range = NULL;
		return (0);
	}
	bound = max - min;
	ptr = (int *)malloc(sizeof(int) * bound);
	if (ptr == NULL)
		return (-1);
	i = -1;
	while (++i < bound)
		ptr[i] = min + i;
	*range = ptr;
	return (bound);
}
