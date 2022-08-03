/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:59:05 by epark             #+#    #+#             */
/*   Updated: 2022/06/09 11:12:29 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_tabs_size(char **tab)
{
	int	cnt;

	cnt = 0;
	while (tab[cnt])
		cnt++;
	return (cnt);
}

void	ft_swaps(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	size;

	size = ft_get_tabs_size(tab);
	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (++j < size)
		{
			if (cmp(tab[j - 1], tab[j]) > 0)
				ft_swaps(&tab[j - 1], &tab[j]);
		}
	}
}
