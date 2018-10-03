/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_gestion.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 10:55:54 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:38:42 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

int		**new_bin()
{
	int		**new;

	if (!(new = (int **)malloc(sizeof(int *) * 2)))
		return (NULL);
	if (!(new[0] = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	ft_bzero(new[0], 2);
	new[1] = 0;
	return (new);
}

int		bin_len(int **bin)
{
	int		i;

	i = -1;
	while (bin[++i])
		;
	return (i);
}

int		add_bin_line(int ***bin)
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

int		add_bin_int(int ***bin, int n, size_t oct)
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
	(*line)[old_size + 1] = n & 0xff;
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

void	print_bin(int **bin)
{
	int		y;
	int		x;

	y = -1;
	while (bin[++y])
	{
		x = 0;
		while (++x < bin[y][0] + 1)
			printf("%0#4x ", bin[y][x]);
		printf("\n");
	}
}
