/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operations_manager.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 19:23:23 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 19:08:43 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

static int	param_size(int op_code, int oct_code, t_vm vm)
{
	if ((oct_code & 0x03) == 1)
		return (1);
	else if ((oct_code & 0x03) == 2)
		return (vm.op_tab[op_code - 1].dir_size);
	else if ((oct_code & 0x03) == 3)
		return (2);
	return (0);
}

static int	realloc_params(int **params, int size)
{
	if (!(*params = (int *)realloc(*params, size)))
	{
		free(*params);
		return (0);
	}
	return (1);
}

int			*params(t_pro pro, t_vm vm)
{
	int		op_c;
	int		oct_c;
	int		size;
	int		p_num;
	int		*p;

	if (!(p = (int *)malloc(sizeof(int) * 3)))
		return (NULL);
	op_c = vm.reg[pro.pc];
	oct_c = vm.reg[pro.pc + 1];
	size = 2;
	p_num = 0;
	while (((oct_c >> (6 - (p_num * 2))) & 0x03) > 0)
	{
		p[p_num] = num_at_reg(vm, pro.pc + size,
		param_size(op_c, oct_c >> (6 - (p_num * 2)), vm));
		size += param_size(op_c, oct_c >> (6 - (p_num * 2)), vm);
		p_num++;
	}
	return (p);
}

int			param_type(int oct_code, int n)
{
	int		i;

	i = -1;
	oct_code = oct_code >> 2;
	while (2 - ++i > n)
		oct_code = oct_code >> 2;
	return (oct_code & 0x03);
}

int			op_size(int op_code, int oct_code, t_vm vm)
{
	int		oct_size;

	if (op_code > 15 || op_code < 1)
		return (0);
	if (op_code == 1 || op_code == 9 || op_code == 12 || op_code == 15)
		return (vm.op_tab[op_code - 1].dir_size);
	oct_size = 1;
	oct_code = oct_code >> 2;
	while (oct_code > 0)
	{
		oct_size += param_size(op_code, oct_code, vm);
		oct_code = oct_code >> 2;
	}
	return (oct_size);
}
