/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reg_setter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 19:25:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 19:25:58 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		num_at_reg(t_vm vm, int reg, size_t size)
{
	long		n;

	n = 0;
	while (size-- > 0)
	{
		n = n << 8;
		n |= vm.reg[reg];
		reg++;
	}
	return (n);
}

void	set_num_at_reg(t_vm *vm, int pos, size_t reg)
{
	int		i;

	i = REG_SIZE;
	while (--i >= 0)
	{
		vm->reg[pos] = (reg >> (i * 8)) & 0xff;
		pos++;
	}
}
