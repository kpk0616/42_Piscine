/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:38:36 by epark             #+#    #+#             */
/*   Updated: 2022/05/26 00:38:46 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}