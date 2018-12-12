/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operations_exec.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 19:23:23 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 05:55:35 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_live(t_pro *pro, t_vm *vm)
{
	unsigned int	champ;
	int				i;

	champ = num_at_reg(*vm, pro->pc + 1, 4);
	i = -1;
	pro->live++;
	vm->total_live++;
	while (++i < vm->nbr_champs)
	{
		if (vm->champs[i].player == champ)
		{
			vm->champs[i].cur_live += 1;
			vm->champs[i].live = vm->cycles_total;
			vm->champs[i].last_live = vm->cycles_total;
			need_champ_display(vm);
			break ;
		}
	}
	goto_next_operation(pro, vm);
}

void	ft_ld(t_pro *pro, t_vm *vm)
{
	int				p[3];
	int				a;

	params(*pro, *vm, p);
	a = p[0];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == IND_CODE)
		a = num_at_reg(*vm, pro->pc + ((short)p[0] % IDX_MOD), 4);
	pro->reg[p[1]] = a;
	pro->carry = 0;
	if (!a)
		pro->carry = 1;
	goto_next_operation(pro, vm);
}

void	ft_st(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;

	params(*pro, *vm, p);
	a = pro->reg[p[0]];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == REG_CODE)
		pro->reg[p[1]] = a;
	else
		set_num_at_reg(vm, *pro, pro->pc + ((short)p[1] % IDX_MOD), a);
	goto_next_operation(pro, vm);
}

void	ft_add(t_pro *pro, t_vm *vm)
{
	int		p[3];

	params(*pro, *vm, p);
	pro->reg[p[2]] = pro->reg[p[0]] + pro->reg[p[1]];
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm);
}

void	ft_sub(t_pro *pro, t_vm *vm)
{
	int		p[3];

	params(*pro, *vm, p);
	pro->reg[p[2]] = pro->reg[p[0]] - pro->reg[p[1]];
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm);
}

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

void	ft_or(t_pro *pro, t_vm *vm)
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
	pro->reg[p[2]] = a | b;
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm);
}

void	ft_xor(t_pro *pro, t_vm *vm)
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
	pro->reg[p[2]] = a ^ b;
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm);
}

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

void	ft_ldi(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;

	params(*pro, *vm, p);
	a = (short)p[0];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == IND_CODE)
		a = num_at_reg(*vm, pro->pc + (p[0] % IDX_MOD), 4);
	b = (short)p[1];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == REG_CODE)
		b = pro->reg[p[1]];
	pro->reg[p[2]] = num_at_reg(*vm, pro->pc + ((a + b) % IDX_MOD), 4);
	goto_next_operation(pro, vm);
}

void	ft_sti(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;

	params(*pro, *vm, p);
	a = (short)p[1];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == REG_CODE)
		a = pro->reg[p[1]];
	else if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == IND_CODE)
		a = num_at_reg(*vm, pro->pc + ((short)p[1] % IDX_MOD), 4);
	b = (short)p[2];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 2) == REG_CODE)
		b = pro->reg[p[2]];
	set_num_at_reg(vm, *pro, pro->pc + ((a + b) % IDX_MOD), pro->reg[p[0]]);
	goto_next_operation(pro, vm);
}

void	ft_fork(t_pro *pro, t_vm *vm)
{
	short	addr;
	t_pro	*new;

	addr = num_at_reg(*vm, pro->pc + 1, 2);
	if (!(new = new_pro_from_pro(*pro, *vm)))
		return ;
	new->pc = ft_mod(pro->pc + (addr % IDX_MOD), MEM_SIZE);
	new->last_pc = new->pc;
	new->op_code = NEW_OP;
	need_pro_display(vm);
	if (!(vm->pro = realloc(vm->pro, sizeof(t_pro) * (vm->nbr_pro + 1))))
		return ;
	vm->pro[vm->nbr_pro] = new;
	vm->nbr_pro++;
	vm->nbr_pro_alive++;
	goto_next_operation(pro, vm);
}

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

void	ft_lldi(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;

	params(*pro, *vm, p);
	a = (short)p[0];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 0) == IND_CODE)
		a = num_at_reg(*vm, (pro->pc + (short)p[0]), 4);
	b = (short)p[1];
	if (param_type(vm->reg[(pro->pc + 1) % MEM_SIZE], 1) == REG_CODE)
		b = pro->reg[p[1]];
	pro->reg[p[2]] = num_at_reg(*vm, pro->pc + (a + b), 4);
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm);
}

void	ft_lfork(t_pro *pro, t_vm *vm)
{
	short	addr;
	t_pro	*new;

	addr = num_at_reg(*vm, pro->pc + 1, 2);
	if (!(new = new_pro_from_pro(*pro, *vm)))
		return ;
	new->pc = ft_mod(pro->pc + addr, MEM_SIZE);
	new->last_pc = new->pc;
	new->op_code = NEW_OP;
	need_pro_display(vm);
	if (!(vm->pro = realloc(vm->pro, sizeof(t_pro) * (vm->nbr_pro + 1))))
		return ;
	vm->pro[vm->nbr_pro] = new;
	vm->nbr_pro++;
	vm->nbr_pro_alive++;
	goto_next_operation(pro, vm);
}

void	ft_aff(t_pro *pro, t_vm *vm)
{
	int				p[3];
	unsigned		c;

	params(*pro, *vm, p);
	c = pro->reg[p[0]] % 256;
	write(1, &c, 1);
	goto_next_operation(pro, vm);
}
