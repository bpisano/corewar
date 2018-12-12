/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lldi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 22:53:35 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 22:53:49 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_lldi(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;

	params(*pro, *vm, p);
	a = (short)p[0];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == IND_CODE)
		a = num_at_reg(*vm, (pro->pc + (short)p[0]), 4);
	b = (short)p[1];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == REG_CODE)
		b = pro->reg[p[1]];
	pro->reg[p[2]] = num_at_reg(*vm, pro->pc + (a + b), 4);
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm);
}
