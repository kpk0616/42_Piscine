/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:17:15 by epark             #+#    #+#             */
/*   Updated: 2022/05/28 16:47:04 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	count_length(char *src)
{
	unsigned int	length;

	length = 0;
	while (*src)
	{
		src++;
		length++;
	}
	return (length);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	length;
	char			*ptr;

	ptr = dest;
	length = count_length(src);
	if (length < n)
	{
		while (*src)
			*dest++ = *src++;
		while (length < n)
		{
			*dest++ = '\0';
			length++;
		}
	}
	else
	{
		while (*src && n--)
			*dest++ = *src++;
	}
	return (ptr);
}
