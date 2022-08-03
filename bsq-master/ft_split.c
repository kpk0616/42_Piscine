/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:51:44 by boh               #+#    #+#             */
/*   Updated: 2022/06/09 04:27:50 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	sepn_chkr(char *str, char *charset, int wd_idx)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (str[wd_idx] == charset[i])
			return (0);
		i++;
	}
	if (!str[i])
		return (0);
	return (1);
}

int	sepn_cntr(char *str, char *charset)
{
	int	cnt;
	int	i;
	int	sw;

	cnt = 0;
	i = 0;
	sw = 1;
	while (str[i])
	{
		if (sepn_chkr(str, charset, i) == 0)
			sw = 1;
		if (sw == 1 && sepn_chkr(str, charset, i) == 1)
		{
			sw = 0;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	word_len(char *str, char *charset, int wd_idx)
{
	int	i;

	i = 0;
	while (sepn_chkr(str, charset, wd_idx + i))
		i++;
	return (i);
}

char	*word_insr(char *str, char *charset, int wd_idx)
{
	int		i;
	int		wd_len;
	char	*sepd_wd;

	i = 0;
	wd_len = word_len(str, charset, wd_idx);
	sepd_wd = (char *)malloc(sizeof(char) * (wd_len + 1));
	if (!sepd_wd)
		return (0);
	while (i < wd_len)
	{
		sepd_wd[i] = str[wd_idx + i];
		i++;
	}
	sepd_wd[wd_len] = 0;
	return (sepd_wd);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		sw;
	int		wd_idx;
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (sepn_cntr(str, charset) + 1));
	if (!dest)
		return (0);
	i = 0;
	sw = 1;
	wd_idx = 0;
	while (str[i])
	{
		if (sepn_chkr(str, charset, i) == 0)
			sw = 1;
		if (sw == 1 && sepn_chkr(str, charset, i) == 1)
		{
			sw = 0;
			dest[wd_idx++] = word_insr(str, charset, i);
			i += word_len(str, charset, i) - 1;
		}
		i++;
	}
	dest[i] = 0;
	return (dest);
}
