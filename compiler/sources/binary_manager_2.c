/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_manager_2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 13:17:00 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 12:39:16 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

void			add_bin_pos(int *bin, int n, size_t oct)
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
