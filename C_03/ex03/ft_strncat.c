/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:35:12 by epark             #+#    #+#             */
/*   Updated: 2022/05/28 05:44:07 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dest_addr;

	dest_addr = dest;
	while (*dest_addr != '\0')
		dest_addr++;
	while (*src != '\0' && nb--)
		*(dest_addr++) = *(src++);
	*dest_addr = '\0';
	return (dest);
}
