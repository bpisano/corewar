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

void	set_num_at_reg(t_vm *vm, int n, size_t reg)
{
	int			num;
	size_t		curr_reg;
	
	if (reg >= MEM_SIZE)
		reg = MEM_SIZE - reg - 1;
	num = ~n;
	curr_reg = reg;
	while (num > 0)
	{
		vm->reg[curr_reg] = ~(num & 0xff);
		num = num >> 8;
		if (curr_reg < MEM_SIZE)
			curr_reg++;
		else
			curr_reg = 0;
	}
}
