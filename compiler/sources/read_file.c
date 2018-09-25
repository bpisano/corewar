/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:48:29 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 12:20:27 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

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
