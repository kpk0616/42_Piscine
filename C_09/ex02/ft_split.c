/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epark <epark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:19:07 by epark             #+#    #+#             */
/*   Updated: 2022/06/06 19:52:39 by epark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (*(charset + i))
	{
		if (c == *(charset + i))
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (*(str + i))
	{
		if (is_separator(*(str + i + 1), charset) == 1 \
			&& is_separator(*(str + i), charset) == 0)
			word_count++;
		i++;
	}
	return (word_count);
}

void	write_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (is_separator(*(src + i), charset) == 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
}

void	write_result(char **result, char *str, char *charset)
{
	int		i;
	int		j;
	int		w_index;

	w_index = 0;
	i = 0;
	while (*(str + i))
	{
		if (is_separator(*(str + i), charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_separator(*(str + i + j), charset) == 0)
				j++;
			result[w_index] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(result[w_index], str + i, charset);
			i += j;
			w_index++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word_count;

	word_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	result[word_count] = 0;
	write_result(result, str, charset);
	return (result);
}
