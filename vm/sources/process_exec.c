/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_exec.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 18:23:20 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 17:20:04 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	exec_op(int op_code, t_pro *pro, t_vm *vm)
{
	void	(*functions[16])(t_pro *, t_vm *);

	functions[0] = ft_live;
	functions[1] = ft_ld;
	functions[2] = ft_st;
	functions[3] = ft_add;
	functions[4] = ft_sub;
	functions[5] = ft_and;
	functions[6] = ft_or;
	functions[7] = ft_xor;
	functions[8] = ft_zjmp;
	functions[9] = ft_ldi;
	functions[10] = ft_sti;
	functions[11] = ft_fork;
	functions[12] = ft_lld;
	functions[13] = ft_lldi;
	functions[14] = ft_lfork;
	functions[15] = ft_aff;
	functions[op_code - 1](pro, vm);
}

void	exec_pro(t_pro *pro, t_vm *vm)
{
	int		op_code;
	int		oct_code;

	oct_code = vm->reg[(pro->pc + 1) % MEM_SIZE];
	op_code = pro->op_code;
	if (op_code < 17 && op_code > 0)
	{
		if (!incorrect_param(*pro, *vm, op_code))
		{
			pro->op_size = op_size(op_code, oct_code, *vm);
			exec_op(op_code, pro, vm);
		}
		else
		{
			pro->op_size = op_size(op_code, oct_code, *vm);
			goto_next_operation(pro, vm);
		}
	}
	else
		goto_next_operation(pro, vm);
}

void	new_op(t_pro *pro, t_vm *vm)
{
	int		op_code;

	op_code = vm->reg[pro->pc];
	pro->op_size = 0;
	pro->cycles = 0;
	pro->op_code = 0;
	if (op_code >= 1 && op_code <= 16)
	{
		pro->op_code = op_code;
		pro->cycles = vm->op_tab[op_code - 1].cycles;
	}
}
