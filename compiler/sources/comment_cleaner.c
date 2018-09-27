/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   comment_cleaner.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 18:21:30 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/27 16:12:00 by bpisano     ###    #+. /#+    ###.fr     */
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
