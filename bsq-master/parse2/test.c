# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void    ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

void    ft_putstr_buf(char *buf, int size)
{
	int     i;

	i = 0;
	while (i < size)
	{
		ft_putchar(buf[i], 1);
		i++;
	}
	ft_putchar('\n', 1);
	ft_putchar('\n', 1);
}

int     main(void)
{
	int     i;
	int     file;
	char    **bufs;

	bufs = malloc(sizeof(char*) * 5);
	i = 0;
	file = open("plateau1000", O_RDWR);
	while (i < 5)
	{
		bufs[i] = malloc(sizeof(char) * 100);
		read(file, bufs[i], 100);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		ft_putstr_buf(bufs[i], 100);
		i++;
	}
}
