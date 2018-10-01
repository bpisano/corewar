/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 12:03:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 14:33:10 by bpisano     ###    #+. /#+    ###.fr     */
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

char			***new_cmd_lines()
{
	char	***new;
	
	if (!(new = (char ***)malloc(sizeof(char **))))
		return (NULL);
	new[0] = 0;
	return (new);
}

int				add_cmd_line(char ****cmd_lines, char *line)
{	
	int		len;
	char	**split;
	
	if (!(split = ft_strsplit(line, ' ')))
		return (0);
	len = cmd_len(*cmd_lines);
	if (!(*cmd_lines = realloc(*cmd_lines, sizeof(char **) * (len + 1))))
	{
		free_split(&split);
		return (0);
	}
	(*cmd_lines)[len] = split;
	(*cmd_lines)[len + 1] = 0;
	return (1);
}
