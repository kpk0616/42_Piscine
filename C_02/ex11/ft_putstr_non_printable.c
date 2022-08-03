/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:07:02 by epark             #+#    #+#             */
/*   Updated: 2022/05/30 00:08:00 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	to_hex(unsigned char *c)
{
	unsigned char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex[*c / 16], 1);
	write(1, &hex[*c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*c;

	while (*str)
	{
		c = (unsigned int)*str;
		if ((c >= 0 && c <= 31) || c == 127)
		{
			to_hex(&c);
		}
		else
			write(1, str, 1);
		str++;
	}
}
