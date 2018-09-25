/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 18:50:47 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 18:50:56 by bpisano     ###    #+. /#+    ###.fr     */
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

static void		write_int(int n)
{
	
}

int				write_bin(int *bin, char *file_name)
{
	int		i;
	int		fd;
	
	if ((fd = open(file_name, O_RDWR | O_CREAT)) < 0)
		return (0);
	i = 0;
	while (++i <= bin[0])
		write(fd, "a", sizeof(int));
	return (1);
}