/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 15:09:14 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 16:59:13 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char			*file_name(char *arg)
{
	int		i;
	char	**split;

	split = ft_strsplit(arg, '.');
	i = -1;
	while (split[++i])
	{
		if (i == 0)
			continue ;
		free(split[i]);
	}
	free(split);
	return (split[0]);
}

static void		write_int(int fd, int n, size_t size)
{
	unsigned char	number;

	if (!size)
		return ;
	write_int(fd, n >> 8, size - 1);
	number = n & 0xff;
	write(fd, &number, 1);
}

void			write_header(t_head head, int fd)
{
	int		i;

	write_int(fd, head.magic, 4);
	i = -1;
	while (++i < PROG_NAME_LENGTH)
		write_int(fd, head.prog_name[i], 1);
	write_int(fd, head.prog_size, 8);
	i = -1;
	while (++i < COMMENT_LENGTH)
		write_int(fd, head.comment[i], 1);
}

void			write_bin(int **bin, int fd)
{
	int		y;
	int		x;
	
	write_int(fd, 0, 4);
	y = -1;
	while (bin[++y])
	{
		x = -1;
		while (++x < bin[y][0])
			write_int(fd, bin[y][x + 1], 1);
	}
}
