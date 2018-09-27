/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_gestion.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 10:55:54 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 12:34:14 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

int		init_bin(t_bin *bin)
{
	if (!(bin->bin = (int *)malloc(sizeof(int))))
		return (0);
	bin->bin[0] = 0;
	bin->size = 0;
	return (1);
}

int		add_int_to_bin(t_bin *bin, int n, size_t size)
{
	if (!size)
		return (1);
	if (!add_int_to_bin(bin, n >> 8, size - 1))
		return (0);
	if (!(bin->bin = (int *)realloc(bin->bin, sizeof(int) * (bin->size + 2))))
		return (0);
	bin->bin[bin->size] = n & 0xff;
	bin->bin[bin->size + 1] = 0;
	bin->size++;
	return (1);
}

void	free_bin(t_bin *bin)
{
	free(bin->bin);
	bin->size = 0;
}
