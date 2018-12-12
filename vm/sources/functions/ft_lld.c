/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lld.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 22:54:02 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 22:54:08 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_lld(t_pro *pro, t_vm *vm)
{
	int				p[3];
	unsigned int	a;

	params(*pro, *vm, p);
	a = p[0];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == IND_CODE)
		a = num_at_reg(*vm, pro->pc + (short)p[0], 4);
	pro->reg[p[1]] = a;
	pro->carry = 0;
	if (!a)
		pro->carry = 1;
	goto_next_operation(pro, vm);
}
