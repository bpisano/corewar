/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:48:29 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 12:58:36 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

void	free_file_lines(char ***tab)
{
	int		i;

	i = 0;
	while (tab[0][i])
	{
		free(tab[0][i]);
		i++;
	}
	free(tab[0]);
}

char	**read_file(char *filename)
{
	int		fd;
	int		i;
	char	**str;

	i = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	if (!(str = (char **)malloc(sizeof(char *))))
		return (0);
	while (get_next_line(fd, str + i) > 0)
	{
		i++;
		str = realloc(str, (i + 1) * sizeof(char *));
	}
	str[i] = 0;
	return (str);
}
