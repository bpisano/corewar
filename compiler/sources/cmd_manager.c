/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 14:07:03 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 14:07:28 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char	***new_cmd_lines()
{
	char	***new;
	
	if (!(new = (char ***)malloc(sizeof(char **))))
		return (NULL);
	new[0] = 0;
	return (new);
}

int		add_cmd_line(char ****cmd_lines, char *line)
{	
	char	**split;
	
	if (!(split = ft_strsplit(line, ' ')))
		return (0);
	if (!(*cmd_lines = (char ***)realloc(sizeof(char **) * 2)))
	{
		free_split(&split);
		return (0);
	}
	(*cmd_lines)[len + 1] = split;
	(*cmd_lines)[len + 2] = 0;
	return (1);
}
