/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:48:29 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 17:37:54 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

static char		add_line(char ***file_lines, char *line)
{
	int		i;

	i = -1;
	while ((*file_lines)[++i])
		;
	if (!(*file_lines = realloc(*file_lines, sizeof(char *) * (i + 2))))
		return (0);
	(*file_lines)[i] = line;
	(*file_lines)[i + 1] = 0;
	return (1);
}

char			is_comment(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (ft_isspace(str[++i]))
		;
	return (str[i] == COMMENT_CHAR);
}

char			**read_file(int fd)
{
	int		i;
	char	**file_lines;
	char	*line;

	i = 0;
	if (!(file_lines = (char **)ft_memalloc(sizeof(char *))))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		++i;
		if (ft_str_is_empty(line) || is_comment(line))
		{
			free(line);
			continue ;
		}
		if (!verify_syntax(&line, i))
		{
			free(line);
			free_split(file_lines);
			return (NULL);
		}
		add_line(&file_lines, line);
	}
	return (file_lines);
}
