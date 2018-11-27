/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operation_checker.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 18:23:20 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 17:20:04 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		incorrect_param(t_pro pro, t_vm vm, int op_code)
{
	int		oct_code;
	int		i;
	int		p;
	int		param[3];

	if (!vm.op_tab[op_code - 1].codage_octal)
		return (0);
	oct_code = vm.reg[(pro.pc + 1) % MEM_SIZE];
	i = -1;
	params(pro, vm, param);
	while (++i < vm.op_tab[op_code - 1].nbr_arg)
	{
		p = oct_code >> (2 * (3 - i));
		if ((p & vm.op_tab[op_code - 1].arg[i]) == 0)
			return (1);
		if ((p & REG_CODE) && (param[i] < 1
		|| param[i] > REG_NUMBER))
			return (1);
	}
	return (0);
}
