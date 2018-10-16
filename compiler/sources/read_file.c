/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:48:29 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:06:52 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

int		is_comment(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (ft_isspace(str[++i]))
		;
	return (str[i] == COMMENT_CHAR);
}

char	**read_file(int fd)
{
	int		i;
	char	**file_lines;
	char	*line;

	i = -1;
	if (!(file_lines = (char **)ft_memalloc(sizeof(char *))))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_str_is_empty(line) || is_comment(line))
		{
			free(line);
			continue ;
		}
		printf("%s\n", line);
		if (!verify_syntax(&line))
		{
			printf("lol\n");
			free(line);
			free_split(&file_lines);
			return (NULL);
		}
		printf("%s\n", line);
		file_lines = (char **)realloc(file_lines, sizeof(char *) * (++i + 2));
		file_lines[i] = line;
		file_lines[i + 1] = 0;
	}
	return (file_lines);
}
