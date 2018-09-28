/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 14:07:03 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 14:07:28 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char	***new_cmd_lines()
{
	char	***new;
	
	if (!(new = (char ***)malloc(sizeof(char **))))
		return (NULL);
	new[0] = 0;
	return (new);
}

int		add_cmd_line(char ****cmd_lines)
{
	int		len;
	
	len = -1;
	while ((*cmd_lines)[++i])
		;
	if (!(*cmd_lines = (char ***)realloc(sizeof(char **) * (len + 2))))
		return (0);
	(*cmd_lines)[len + 1] = 0;
	(*cmd_lines)[len + 2] = 0;
	return (1);
}
