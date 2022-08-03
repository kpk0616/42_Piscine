/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:17:15 by epark             #+#    #+#             */
/*   Updated: 2022/06/08 21:27:24 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int				i;
	unsigned int	len;
	char			*result;

	len = ft_strlen(strs[0]);
	i = 1;
	while (i < size)
	{
		len += ft_strlen(sep);
		len += ft_strlen(strs[i]);
		i++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (0);
	*result = '\0';
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (!(i == size - 1))
			result = ft_strcat(result, sep);
		i++;
	}
	return (result);
}
