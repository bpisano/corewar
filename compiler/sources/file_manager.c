/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 12:19:00 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 19:26:12 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "compiler.h"

char			*file_name(char *arg)
{
	int 	i;
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

int				write_header(t_head head, char *file_name)
{
	int		i;
	int		fd;
	
	if ((fd = open(file_name, O_RDWR | O_CREAT)) < 0)
		return (0);
	write_int(fd, head.magic, 4);
	i = -1;
	while (++i < PROG_NAME_LENGTH)
		write_int(fd, head.prog_name[i], 1);
	i = -1;
	while (++i < COMMENT_LENGTH)
		write_int(fd, head.comment[i], 1);
	return (1);
}

int				write_bin(int *bin, char *file_name)
{
	int		i;
	int		fd;
	
	if ((fd = open(file_name, O_RDWR | O_CREAT)) < 0)
		return (0);
	/*
	i = 0;
	while (++i <= bin[0])
		write_int(fd, bin[i]);
	*/
	write_int(fd, 0xea83f3, 4);
	return (1);
}