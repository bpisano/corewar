/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_and.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 22:57:48 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 22:57:54 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_and(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;

	params(*pro, *vm, p);
	a = p[0];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == IND_CODE)
		a = num_at_reg(*vm, pro->pc + ((short)p[0] % IDX_MOD), 4);
	b = p[1];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == REG_CODE)
		b = pro->reg[p[1]];
	else if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == IND_CODE)
		b = num_at_reg(*vm, pro->pc + ((short)p[1] % IDX_MOD), 4);
	pro->reg[p[2]] = a & b;
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm);
}
