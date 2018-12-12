/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ldi.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 22:56:05 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 22:56:16 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_ldi(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;

	params(*pro, *vm, p);
	a = (short)p[0];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == IND_CODE)
		a = num_at_reg(*vm, pro->pc + (p[0] % IDX_MOD), 4);
	b = (short)p[1];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == REG_CODE)
		b = pro->reg[p[1]];
	pro->reg[p[2]] = num_at_reg(*vm, pro->pc + ((a + b) % IDX_MOD), 4);
	goto_next_operation(pro, vm);
}
