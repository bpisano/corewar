/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:48:29 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 12:58:36 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

void	free_file_lines(char ***tab)
{
	int		i;

	i = -1;
	while ((*tab)[++i])
		free((*tab)[i]);
	free(*tab);
}

char	**read_file(char *filename)
{
	int		fd;
	int		i;
	char	**str;
	char	*line;

	i = -1;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	if (!(str = (char **)malloc(sizeof(char *))))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_str_is_empty(line))
		{
			free(line);
			continue ;
		}
		str[++i] = line;
		str = realloc(str, (i + 2) * sizeof(char *));
	}
	str[i + 1] = 0;
	return (str);
}
