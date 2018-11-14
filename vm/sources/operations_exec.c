/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opreations_exec.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 19:23:23 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 19:23:23 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	live(t_pro *pro, t_vm *vm)
{
	int		champ;
	int		i;
	
	champ = num_at_reg(*vm, pro->pc + 1, 4);
	i = -1;
	while (vm->champs[++i])
	{
		if (vm->champs[i]->player == (unsigned char)champ)
		{
			vm->champs[i]->cur_live += 1;
			break ;
		}
	}
	goto_next_operation(pro, *vm);
}

void	ld(t_pro *pro, t_vm *vm)
{
	int		*p;
	
	if (!(p = params(*pro, *vm)))
		return ;
	pro->reg[p[1]] = p[0] % IDX_MOD;
	pro->carry = 1;
	free(p);
	goto_next_operation(pro, *vm);
}

void	st(t_pro *pro, t_vm *vm)
{
	int		*p;

	if (!(p = params(*pro, *vm)))
		return ;
	if (param_type(vm->reg[pro->pc + 1], 1) == 1)
		set_num_at_reg(vm, pro->reg[p[1]], REG_SIZE);
	else
		set_num_at_reg(vm, p[1], IND_SIZE);
	free(p);
	goto_next_operation(pro, *vm);
}

void	add(t_pro *pro, t_vm *vm)
{
	int		*p;

	if (!(p = params(*pro, *vm)))
		return ;
	pro->reg[p[2]] = p[0] + p[1];
	free(p);
	goto_next_operation(pro, *vm);
}

void	sub(t_pro *pro, t_vm *vm)
{
	int		*p;

	if (!(p = params(*pro, *vm)))
		return ;
	pro->reg[p[2]] = p[0] - p[1];
	free(p);
	goto_next_operation(pro, *vm);
}

void	and(t_pro *pro, t_vm *vm)
{
	int		*p;
	int		a;
	int		b;

	if (!(p = params(*pro, *vm)))
		return ;
	if (param_type(vm->reg[pro->pc + 1], 0) == 1)
		a = pro->reg[p[0]];
	else
		a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 1) == 1)
		b = pro->reg[p[1]];
	else
		b = p[1];
	pro->reg[p[2]] = a & b;
	free(p);
	goto_next_operation(pro, *vm);
}

void	or(t_pro *pro, t_vm *vm)
{
	int		*p;
	int		a;
	int		b;

	if (!(p = params(*pro, *vm)))
		return ;
	if (param_type(vm->reg[pro->pc + 1], 0) == 1)
		a = pro->reg[p[0]];
	else
		a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 1) == 1)
		b = pro->reg[p[1]];
	else
		b = p[1];
	pro->reg[p[2]] = a | b;
	free(p);
	goto_next_operation(pro, *vm);
}

void	xor(t_pro *pro, t_vm *vm)
{
	int		*p;
	int		a;
	int		b;

	if (!(p = params(*pro, *vm)))
		return ;
	if (param_type(vm->reg[pro->pc + 1], 0) == 1)
		a = pro->reg[p[0]];
	else
		a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 1) == 1)
		b = pro->reg[p[1]];
	else
		b = p[1];
	pro->reg[p[2]] = a ^ b;
	free(p);
	goto_next_operation(pro, *vm);
}

void	zjmp(t_pro *pro, t_vm *vm)
{
	int		addr;

	addr = num_at_reg(*vm, pro->pc + 1, 4);
	if (pro->carry)
		increment_pc(addr % IDX_MOD, pro);
	else
		goto_next_operation(pro, *vm);
}

void	ldi(t_pro *pro, t_vm *vm)
{
	int		*p;
	int		a;
	int		b;

	if (!(p = params(*pro, *vm)))
		return ;
	if (param_type(vm->reg[pro->pc + 1], 0) == 1)
		a = pro->reg[p[0]];
	else
		a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 1) == 1)
		b = pro->reg[p[1]];
	else
		b = p[1];
	pro->reg[p[2]] = num_at_reg(*vm, pro->pc + (a + b) % IDX_MOD, 4);
	free(p);
	goto_next_operation(pro, *vm);
} 
