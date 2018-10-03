/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:48:29 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 19:28:50 by anamsell    ###    #+. /#+    ###.fr     */
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

int		is_comment(char *str)
{
	if (!str)
		return (0);
	return (str[0] == COMMENT_CHAR);
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
		if (ft_str_is_empty(line) || is_comment(line))
		{
			free(line);
			continue ;
		}
		str[++i] = no_comment(line);
		str_replace(&(str[i]), '\t', ' ');
		str = realloc(str, sizeof(char *) * (i + 2));
	}
	str[i + 1] = 0;
	return (str);
}
