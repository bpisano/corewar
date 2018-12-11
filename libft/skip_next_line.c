/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   skip_next_line.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 14:10:49 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 14:12:36 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	skip_next_line(const int fd)
{
	int		ret;
	char	*line;

	ret = get_next_line(fd, &line);
	if (ret > 0)
		free(line);
}
