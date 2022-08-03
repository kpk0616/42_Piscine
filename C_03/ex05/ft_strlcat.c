/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:28:46 by epark             #+#    #+#             */
/*   Updated: 2022/05/31 19:50:33 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	count_len(char *src)
{
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	num;

	dest_length = count_len(dest);
	src_length = count_len(src);
	num = dest_length;
	if (dest_length >= size)
		return (src_length + size);
	else
	{
		while (*dest)
		{
			dest++;
		}
		while (*src && num < size - 1)
		{
			*dest++ = *src++;
			num++;
		}
		*dest = '\0';
		return (dest_length + src_length);
	}
}
