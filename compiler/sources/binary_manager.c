/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 10:55:54 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 09:55:43 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

int		bin_len(int **bin)
{
	int		i;

	i = -1;
	while (bin[++i])
		;
	return (i);
}

char	add_bin_line(int ***bin)
{
	int		len;
	int		*line;

	len = bin_len(*bin);
	if (!(*bin = (int **)realloc(*bin, sizeof(int *) * (len + 2))))
		return (0);
	if (!(line = (int *)malloc(sizeof(int) * 2)))
		return (0);
	line[0] = 0;
	line[1] = 0;
	(*bin)[len] = line;
	(*bin)[len + 1] = 0;
	return (1);
}

char	add_bin_int(int ***bin, int n, size_t oct)
{
	int		col;
	int		old_size;
	int		**line;

	if (!oct)
		return (1);
	col = bin_len(*bin) - 1;
	if (!add_bin_int(bin, n >> 8, oct - 1))
		return (0);
	line = &((*bin)[col]);
	old_size = (*line)[0];
	if (!(*line = (int *)realloc(*line, sizeof(int) * (old_size + 3))))
		return (0);
	add_bin_pos(&((*line)[old_size + 1]), n, 1);
	(*line)[old_size + 2] = 0;
	(*line)[0] = old_size + 1;
	return (1);
}

void	free_bin(int ***bin)
{
	int		i;
	int		len;

	i = -1;
	len = bin_len(*bin);
	while ((*bin)[++i])
		free((*bin)[i]);
	free(*bin);
}
