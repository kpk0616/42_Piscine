/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:58:55 by epark             #+#    #+#             */
/*   Updated: 2022/06/09 11:12:15 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_get_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	size;

	size = ft_get_tab_size(tab);
	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (++j < size)
		{
			if (ft_strcmp(tab[j - 1], tab[j]) > 0)
				ft_swap(&tab[j - 1], &tab[j]);
		}
	}
}
