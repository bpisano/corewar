/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 10:55:54 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 11:12:02 by bpisano     ###    #+. /#+    ###.fr     */
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
	
	split = ft_strsplit(' ', str);
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

int				add_head_to_bin(int **bin, char **file_lines)
{
	int		i;
	char	*name;
	char	*com;
	
	i = -1;
	name = NULL;
	com = NULL;
	while (file_lines[++i] && (!name || !com))
	{
		if (name = header_type(file_lines[i], ".name") && !name)
			add_str_to_bin(bin, name);
		else if (desc = header_type(file_lines[i], ".comment") && !com)
			add_str_to_bin(bin, com);
		else
		{
			name == NULL ? name : free(name);
			com == NULL ? desc : free(com);
			return (1);
		}
	}
	free(name);
	free(com);
	return (0);
}
