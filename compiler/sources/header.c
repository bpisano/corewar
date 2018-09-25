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
		(name_len = ft_strlen(split[1])) < 3)
	{
		free_split(&split);
		return (NULL);
	}
	sub = ft_strsub(split[1], 1, name_len - 2);
	free_split(&split);
	return (sub);
}

int				add_head_to_bin(char **bin, char **file_lines)
{
	int		i;
	int		error;
	char	*name;
	char	*com;

	i = -1;
	while (file_lines[++i] && !(name && com))
	{
		printf("%s\n", file_lines[i]);
		if ((name = header_type(file_lines[i], ".name")) && !name)
			continue ;
		else if ((com = header_type(file_lines[i], ".comment")) && !com)
			continue ;
		else
		{
			printf("%s, %s\n", name, com);
			error = name == NULL ? 1 : 2;
			name == NULL ? name : free(name);
			com == NULL ? com : free(com);
			return (error);
		}
	}
	add_str_to_bin(bin, name);
	add_str_to_bin(bin, com);
	free(name);
	free(com);
	return (0);
}
