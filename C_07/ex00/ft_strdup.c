/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:17:06 by epark             #+#    #+#             */
/*   Updated: 2022/06/07 12:27:13 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *src)
{
	int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = str_len(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr != NULL)
	{
		while (*(src + i))
		{
			*(ptr + i) = *(src + i);
			i++;
		}
		*(ptr + i) = '\0';
	}
	return (ptr);
}
