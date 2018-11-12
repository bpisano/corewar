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

int		num_at_reg(t_vm vm, size_t reg, size_t size)
{
	int		num;
	size_t	size_done;
	size_t	i;
	
	if (reg >= MEM_SIZE)
		reg = MEM_SIZE - reg - 1;
	size_done = size;
	i = reg;
	while (size_done > 0)
	{
		num = num << 8;
		num |= vm.reg[i];
		if (i < MEM_SIZE)
			i++;
		else
			i = 0; 
	}
	return (num);
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
