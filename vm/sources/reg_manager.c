/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reg_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 19:25:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 05:34:53 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		num_at_reg(t_vm vm, int pos, size_t size)
{
	int		n;

	n = 0;
	while (size-- > 0)
	{
		n = n << 8;
		n |= vm.reg[pos];
		pos++;
	}
	return (n);
}

void			set_num_at_reg(t_vm *vm, int pos, size_t reg)
{
	int		i;

	i = REG_SIZE;
	while (--i >= 0)
	{
		vm->reg[pos] = (reg >> (i * 8)) & 0xff;
		pos++;
	}
}
