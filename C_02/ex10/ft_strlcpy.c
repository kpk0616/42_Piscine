/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:44:00 by epark             #+#    #+#             */
/*   Updated: 2022/05/30 00:07:02 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count(char *arr)
{
	int	num;

	num = 0;
	while (*arr)
	{
		num++;
		arr++;
	}
	return (num);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	int					num;

	i = 0;
	num = ft_count(src);
	while (*src && i < size - 1)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = '\0';
	return (num);
}
