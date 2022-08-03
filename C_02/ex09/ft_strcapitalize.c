/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:42:31 by epark             #+#    #+#             */
/*   Updated: 2022/05/26 18:56:12 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char *str)
{
	if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		return (1);
	else
		return (0);
}

int	is_num(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (1);
	else
		return (0);
}

void	to_upper(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str = *str - 'a' + 'A';
	}
}

void	to_lower(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
	{
		*str = *str - 'A' + 'a';
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*c;

	c = str;
	if (is_alpha(str))
		to_upper(str);
	str++;
	while (*str)
	{
		if (is_alpha(str))
		{
			if (!is_alpha(str - 1) && !is_num(str - 1))
				to_upper(str);
			else
				to_lower(str);
		}
		str++;
	}
	return (c);
}
