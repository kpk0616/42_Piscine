/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:15:05 by boh               #+#    #+#             */
/*   Updated: 2022/06/09 05:06:03 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	file_size(void)
{
	int		i;
	int		fd;
	int		arr[3];
	char	explr[10240];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	fd = open("./input1.txt", O_RDONLY);//이 부분에서 파일 인풋을 str으로 받는 방법을 고려할 것
	if (fd > 0)
	{
		explr[10239] = 0;
		read(fd, explr, 10239);
		while (explr[arr[0]] != '\n')
			arr[0]++;
		arr[1] = arr[0]++; //arr[1] is nb of 1st \n letter
		while (explr[arr[0]] != '\n')
			arr[0]++; //arr[0] is nb of 2nd \n letter, arr[0] - arr[1] - 1 is col.
		i = -1;
		while (++i < arr[1] - 3)
			arr[2] = arr[2] * 10 + explr[i] - '0'; //arr[2] is row
		arr[0] = arr[0] - arr[1] - 1; //arr[0] is col
	}
	close(fd);
	return (arr[1] + (arr[0] + 1) * arr[2] + 1);
}

char	*single_map(int size)
{
	int		fd;
	char	*org_map;

	fd = open("./input1.txt", O_RDONLY);
	if (fd > 0)
	{
		org_map = malloc(sizeof(char) * (size + 1));
		if (!org_map)
			return (0);
		read(fd, org_map, size);
	}
	else
		return (0);
	close(fd);
	return (org_map);
}

char	**map_maker(int size)
{
	char	*org_map;
	char	**map;

	org_map = single_map(size);
	map = ft_split(org_map, "\n");
	free(org_map);
	return (map);
}

char	*ft_buf(char **map)
{
	int		i;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * 4);
	i = 0;
	while (map[0][i])
		i++;
	buf[0] = map[0][i - 3];
	buf[1] = map[0][i - 2];
	buf[2] = map[0][i - 1];
	buf[3] = 0;
	return (buf);
}

int	row_info(char **map)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (map[0][i])
		i++;
	j = 0;
	while (j < i - 3)
	{
		nb = nb * 10 + map[0][j] - '0';
		j++;
	}
	return (nb);
}

int	main(void)
{
	int		i;
	int		row_max;
	int		col_max;
	char	**map;

	map = map_maker(file_size());
	i = 1;
	col_max = 0;
	row_max = 1;
	while (map[1][col_max])
		col_max++;
	while (map[row_max])
		row_max++;
	// map_check();//2
	// transform(map, ft_buf); //3
	// change(map, row_max, col_max); //4
	// nbr_to_char(map, ft_buf, num, row_max, col_max);//5
	// ft_output(map, row_max, col_max); //6
	while (i < row_max)
	{
		write(1, map[i], col_max);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
//꽉 찬 문자를 char에 저장해둬야 한다
