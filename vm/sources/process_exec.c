/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_exec.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 18:23:20 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 18:23:38 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	exec_op(int op_num, t_pro *pro, t_vm *vm)
{
	//if (op_num == 0)
		
}

void	exec_pro(t_pro *pro, t_vm *vm)
{
	int		op_num;
	
	op_num = vm->reg[pro->pc];
	if (op_num > 15)
	{
		increment_pc(1, pro);
		return ;
	}
	exec_op(op_num, pro, vm);
}
