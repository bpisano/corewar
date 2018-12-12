/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file_verification_2.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 12:07:31 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 11:44:33 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char	corewar_alpha(char c)
{
	return (c == LABEL_CHAR || c == DIRECT_CHAR || ft_strchr(LABEL_CHARS, c));
}

char	str_start_by(char *str, char *start)
{
	int		i;

	if (!str || !start)
		return (0);
	i = -1;
	while (str[++i] && start[i])
		if (str[i] != start[i])
			return (0);
	return (start[i] == 0);
}

int		label_offset(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != LABEL_CHAR)
		if (!ft_strchr(LABEL_CHARS, str[i]))
			return (0);
	if (str[i] == LABEL_CHAR && i > 0)
		return (i + 1);
	return (0);
}

char	have_two_separator(char *line)
{
	int		i;

	if (ft_strlen(line) < 2)
		return (0);
	i = 0;
	while (line[++i])
		if (line[i - 1] == SEPARATOR_CHAR && line[i] == SEPARATOR_CHAR)
			return (1);
	return (0);
}
