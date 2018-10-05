/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file_verification.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:54:47 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 19:17:32 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

static int	match_pattern(char *str)
{
	int		i;

	i = 0;
	if (ft_str_is_empty(str) || ft_strlen(str) == 0)
		return (0);
	while (ft_isspace(str[i]) && str[i])
		i++;
	while (corewar_alpha(str[i]) && str[i])
		i++;
	while (ft_isspace(str[i]) && str[i])
		i++;
	return (str[i] == 0);
}

int			have_only_label(char *line, int *i)
{
	if (str_start_by(line, NAME_CMD_STRING)
		|| str_start_by(line, COMMENT_CMD_STRING))
		return (1);
	*i = label_offset(line);
	if (ft_str_is_empty(line + *i))
		return (1);
	while (ft_isspace(line[*i]))
		(*i)++;
	while (ft_isalpha(line[*i]))
		(*i)++;
	return (0);
}

int			have_separator_at_last(char *line)
{
	char	*trim;
	int		last_char;

	trim = ft_strtrim(line);
	last_char = ft_strlen(trim) - 1;
	if (trim[last_char] == SEPARATOR_CHAR)
	{
		free(trim);
		return (1);
	}
	free(trim);
	return (0);
}

int			arguments_are_correct_formatted(char *line)
{
	int		i;
	char	**split;

	split = ft_strsplit(line, SEPARATOR_CHAR);
	if (ft_tablen(split) == 0)
	{
		free_split(&split);
		return (0);
	}
	i = -1;
	while (split[++i])
		if (!match_pattern(split[i]))
		{
			free_split(&split);
			return (0);
		}
	free_split(&split);
	return (1);
}

int			verify_syntax(char **line)
{
	int		i;
	char	**split;

	*line = no_comment(*line);
	if (have_only_label(*line, &i))
		return (1);
	if (have_separator_at_last(*line + i))
		return (0);
	if (!arguments_are_correct_formatted(*line + i))
		return (0);
	str_replace(line, SEPARATOR_CHAR, ' ');
	return (1);
}