/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_manager_2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 13:17:00 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 09:55:35 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

void	add_bin_pos(int *bin, int n, size_t oct)
{
	int		i;

	if (oct <= 0)
		return ;
	add_bin_pos(bin + 1, n, oct - 1);
	i = -1;
	while (++i < oct - 1)
		n = n >> 8;
	bin[0] = n & 0xff;
}

int		bin_size(int **bin)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (bin[++i])
		size += bin[i][0];
	return (size);
}

int		**new_bin(void)
{
	int		**new;

	if (!(new = (int **)malloc(sizeof(int *) * 2)))
		return (NULL);
	new[0] = NULL;
	return (new);
}
