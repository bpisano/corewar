/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file_verification_2.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 12:58:01 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 12:58:12 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

int		corewar_alpha(char c)
{
	return (c == LABEL_CHAR || c == DIRECT_CHAR || ft_strchr(LABEL_CHARS, c));
}

int		str_start_by(char *str, char *start)
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
