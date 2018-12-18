/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 10:55:54 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 17:16:14 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

static int		split_len(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
		;
	return (i);
}

static char		*header_type(char *str, char *type)
{
	char	**split;
	char	*trim_type;
	char	*str1;

	if (!(split = ft_strsplit(str, '\"')))
		return (NULL);
	if (split_len(split) != 2 || !(str[ft_strlen(str) - 1] == '\"'))
	{
		free_split(split);
		return (NULL);
	}
	if (!(trim_type = ft_strtrim(split[0])))
		return (0);
	if (ft_strcmp(type, trim_type) != 0)
	{
		free(trim_type);
		free_split(split);
		return (NULL);
	}
	free(trim_type);
	free(split[0]);
	str1 = split[1];
	free(split);
	return (str1);
}

static char		handle_error(char **name, char **com)
{
	int		error;

	if (!*name)
		error = -1;
	else if (!*com)
		error = -2;
	else
		error = -3;
	*name == NULL ? name : free(*name);
	*com == NULL ? com : free(*com);
	return (error);
}

int				set_header(t_head *head, char **file_lines)
{
	int		i;
	char	*name;
	char	*com;

	i = -1;
	name = NULL;
	com = NULL;
	while (file_lines[++i] && !(name && com))
	{
		if (!name && (name = header_type(file_lines[i], NAME_CMD_STRING)))
			continue ;
		else if (!com && (com = header_type(file_lines[i], COMMENT_CMD_STRING)))
			continue ;
		else
			return (handle_error(&name, &com));
	}
	head->magic = COREWAR_EXEC_MAGIC;
	if (!name || !com)
		return (handle_error(&name, &com));
	set_head_name(head, name);
	set_head_comment(head, com);
	free(name);
	free(com);
	return (i);
}
