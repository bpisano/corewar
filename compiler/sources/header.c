/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 10:55:54 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 12:37:30 by anamsell    ###    #+. /#+    ###.fr     */
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

static void		free_split(char ***split)
{
	int		i;

	i = -1;
	while ((*split)[++i])
		free((*split)[i]);
	free(*split);
}

static char		*header_type(char *str, char *type)
{
	int		i;
	int		begin;
	char	*type_name;
	
	i = -1;
	while (str[++i] == type[i])
		;
	
}

static int		handle_error(char **name, char **com)
{
	int		error;
	
	if (!*name)
		error = 1;
	else if (!*com)
		error = 2;
	else
		error = 5;
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
	while (file_lines[++i])
	{
		if (!name && (name = header_type(file_lines[i], NAME_CMD_STRING)))
			continue ;
		else if (!com && (com = header_type(file_lines[i], COMMENT_CMD_STRING)))
			continue ;
		else
			return (handle_error(&name, &com));
	}
	set_head_name(head, name);
	set_head_comment(head, com);
	free(name);
	free(com);
	return (0);
}
