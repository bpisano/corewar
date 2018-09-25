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

static char		*header_type(char *str, char *name)
{
	int		name_len;
	char	**split;
	char	*sub;

	split = ft_strsplit(str, ' ');
	if (split_len(split) != 2)
	{
		free_split(&split);
		return (NULL);
	}
	if (ft_strcmp(split[0], name) != 0 ||
		(name_len = ft_strlen(split[1])) < 3 ||
		!(split[1][0] == '\"' && split[1][name_len - 1] == '\"'))
	{
		free_split(&split);
		return (NULL);
	}
	sub = ft_strsub(split[1], 1, name_len - 2);
	free_split(&split);
	return (sub);
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

int				add_head_to_bin(int **bin, char **file_lines)
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
	add_num_to_bin(bin, 4, 0x00, 0xea, 0x83, 0xf3);
	add_str_to_bin(bin, name);
	add_str_to_bin(bin, com);ad
	free(name);
	free(com);
	return (0);
}
