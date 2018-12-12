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

int				num_at_reg(t_vm vm, int pos, size_t size)
{
	int		n;

	n = 0;
	pos = pos % MEM_SIZE;
	if (pos < 0)
		pos += MEM_SIZE;
	while (size-- > 0)
	{
		n = n << 8;
		n |= vm.reg[pos % MEM_SIZE];
		pos++;
	}
	return (n);
}

void			set_num_at_reg(t_vm *vm, t_pro pro, int reg_pos,
								unsigned int reg)
{
	int		i;

	i = DIR_SIZE;
	reg_pos = reg_pos % MEM_SIZE;
	if (reg_pos < 0)
		reg_pos += MEM_SIZE;
	while (--i >= 0)
	{
		vm->reg[reg_pos % MEM_SIZE] = (reg >> (i * 8)) & 0xff;
		ui_update_reg(vm, pro, reg_pos % MEM_SIZE);
		reg_pos++;
	}
}
