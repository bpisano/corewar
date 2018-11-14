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

void	exec_op(int op_code, t_pro *pro, t_vm *vm)
{
	void	(*functions[2])(t_pro *, t_vm *);
	
	functions[0] = live;
	functions[1] = ld;
	functions[op_code - 1](pro, vm);
}	

void	exec_pro(t_pro *pro, t_vm *vm)
{
	int		op_code;
	int		op_s;
	
	op_code = vm->reg[pro->pc];
	if (op_code < 16 && op_code > 0)
		exec_op(op_code, pro, vm);
}
