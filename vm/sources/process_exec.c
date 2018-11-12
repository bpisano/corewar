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
	int		op_code;
	int		op_s;
	
	op_code = vm->reg[pro->pc];
	if (op_code > 15 || op_code < 1)
	{
		increment_pc(1, pro);
		return ;
	}
	exec_op(op_code, pro, vm);
	if (op_code == 1 || op_code == 9 || op_code == 12 || op_code == 15)
		op_s = vm->op_tab[op_code].dir_size;
	else
		op_s = op_size(op_code, vm->reg[pro->pc + 1], *vm);
	increment_pc(op_s + 1, pro);
}
