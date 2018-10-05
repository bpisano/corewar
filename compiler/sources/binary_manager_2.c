/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_manager_2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 13:17:00 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 16:53:53 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

static int		oct_size(int n)
{
	int		i;
	int		oct;

	i = 0;
	oct = n;
	while ((oct = oct >> 8))
		i++;
	return (i);
}

void			add_bin_pos(int *bin, int n, size_t oct)
{
	int		i;

	if (!oct)
		return ;
	add_bin_pos(bin + 1, n >> 8, oct - 1);
	i = -1;
	while (++i < oct_size(n) - 1)
		n = n >> 8;
	bin[0] = n & 0xff;
}
