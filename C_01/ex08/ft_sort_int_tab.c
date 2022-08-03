/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:57:54 by epark             #+#    #+#             */
/*   Updated: 2022/05/23 02:31:12 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{	
	int	i;
	int	j;
	int	temp;
	int	*start;

	start = tab;
	i = 1;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (*tab > *(tab + 1))
			{
				temp = *tab;
				*tab = *(tab + 1);
				*(tab + 1) = temp;
			}
			tab++;
			j++;
		}
	tab = start;
	i++;
	}
}
