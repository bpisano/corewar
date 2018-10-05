/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_cleaner.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:54:47 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 13:57:39 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char			*no_comment(char *str)
{
	int		i;
	int		in_quote;
	char	*new;
	char	*trim;

	i = -1;
	in_quote = 0;
	while (str[++i])
	{
		if (str[i] == '\"')
			in_quote = in_quote == 0 ? 1 : 0;
		else if (str[i] == COMMENT_CHAR && !in_quote)
			break ;
	}
	new = ft_strsub(str, 0, i);
	trim = ft_strtrim(new);
	free(str);
	free(new);
	return (trim);
}

void			str_replace(char **str, char c, char rep)
{
	int		i;

	if (!str)
		return ;
	i = -1;
	while ((*str)[++i])
		if ((*str)[i] == c)
			(*str)[i] = rep;
}
