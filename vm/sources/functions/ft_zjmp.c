/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_zjmp.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 22:56:33 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 22:56:39 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_zjmp(t_pro *pro, t_vm *vm)
{
	short	addr;

	addr = num_at_reg(*vm, pro->pc + 1, 2);
	if (pro->carry)
	{
		increment_pc(addr % IDX_MOD, pro, vm);
		pro->op_code = NEW_OP;
	}
	else
		goto_next_operation(pro, vm);
}
