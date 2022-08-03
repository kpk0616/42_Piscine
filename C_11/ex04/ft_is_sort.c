/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:58:39 by epark             #+#    #+#             */
/*   Updated: 2022/06/09 11:45:33 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	tmp;
	int	tmp2;

	tmp2 = 0;
	i = 0;
	while (length-- > 1)
	{
		tmp = f(tab[length], tab[length - 1]);
		if (tmp == 0)
			continue ;
		if (tmp2 == 0)
			tmp2 = tmp;
		else if ((tmp2 < 0 && tmp > 0) || (tmp < 0 && tmp2 > 0))
			return (0);
		i++;
	}
	return (1);
}
