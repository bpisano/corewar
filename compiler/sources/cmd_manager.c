/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 12:03:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 14:37:13 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

static int		cmd_len(char ***cmd)
{
	int		i;

	i = -1;
	while (cmd[++i])
		;
	return (i);
}

char			***new_cmd_lines(void)
{
	char	***new;

	if (!(new = (char ***)malloc(sizeof(char **))))
		return (NULL);
	new[0] = 0;
	return (new);
}

char			add_cmd_line(char ****cmd_lines, char *line)
{
	int		len;
	char	**split;

	if (!(split = ft_strsplit(line, ' ')))
		return (0);
	len = cmd_len(*cmd_lines);
	if (!(*cmd_lines = realloc(*cmd_lines, sizeof(char **) * (len + 2))))
	{
		free_split(split);
		return (0);
	}
	(*cmd_lines)[len] = split;
	(*cmd_lines)[len + 1] = 0;
	return (1);
}
