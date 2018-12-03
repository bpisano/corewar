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
	int				op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	champ = num_at_reg(*vm, pro->pc + 1, 4);
	pro->live++;
	i = -1;
	while (vm->champs[++i])
	{
		if (vm->champs[i]->player == champ)
		{
			vm->champs[i]->cur_live += 1;
			vm->champs[i]->live = vm->cycles_total;
			need_champ_display(vm);
			break ;
		}
	}
	goto_next_operation(pro, vm, op_s);
}

void	ft_ld(t_pro *pro, t_vm *vm)
{
	int				p[3];
	int				a;
	int				op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == IND_CODE)
		a = (short)num_at_reg(*vm, (pro->pc + p[0]) % IDX_MOD, IND_SIZE);
	pro->reg[p[1]] = a;
	pro->carry = 0;
	if (!a)
		pro->carry = 1;
	goto_next_operation(pro, vm, op_s);
}

void	ft_st(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	a = pro->reg[p[0]];
	if (param_type(vm->reg[pro->pc + 1], 1) == REG_CODE)
		pro->reg[p[1]] = a;
	else
		set_num_at_reg(vm, *pro, (pro->pc + (short)p[1] % IDX_MOD), a);
	goto_next_operation(pro, vm, op_s);
}

void	ft_add(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	pro->reg[p[2]] = pro->reg[p[0]] + pro->reg[p[1]];
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm, op_s);
}

void	ft_sub(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	pro->reg[p[2]] = pro->reg[p[0]] - pro->reg[p[1]];
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm, op_s);
}

void	ft_and(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[pro->pc + 1], 0) == IND_CODE)
		a = (short)num_at_reg(*vm, (pro->pc + p[0]) % IDX_MOD, IND_SIZE);
	b = p[1];
	if (param_type(vm->reg[pro->pc + 1], 1) == REG_CODE)
		b = pro->reg[p[1]];
	else if (param_type(vm->reg[pro->pc + 1], 1) == IND_CODE)
		b = (short)num_at_reg(*vm, (pro->pc + p[1]) % IDX_MOD, IND_SIZE);
	pro->reg[p[2]] = a & b;
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm, op_s);
}

void	ft_or(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[pro->pc + 1], 0) == IND_CODE)
		a = (short)num_at_reg(*vm, (pro->pc + p[0]) % IDX_MOD, IND_SIZE);
	b = p[1];
	if (param_type(vm->reg[pro->pc + 1], 1) == REG_CODE)
		b = pro->reg[p[1]];
	else if (param_type(vm->reg[pro->pc + 1], 1) == IND_CODE)
		b = (short)num_at_reg(*vm, (pro->pc + p[1]) % IDX_MOD, IND_SIZE);
	pro->reg[p[2]] = a | b;
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm, op_s);
}

void	ft_xor(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[pro->pc + 1], 0) == IND_CODE)
		a = (short)num_at_reg(*vm, (pro->pc + p[0]) % IDX_MOD, IND_SIZE);
	b = p[1];
	if (param_type(vm->reg[pro->pc + 1], 1) == REG_CODE)
		b = pro->reg[p[1]];
	else if (param_type(vm->reg[pro->pc + 1], 1) == IND_CODE)
		b = (short)num_at_reg(*vm, (pro->pc + p[1]) % IDX_MOD, IND_SIZE);
	pro->reg[p[2]] = a ^ b;
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm, op_s);
}

void	ft_zjmp(t_pro *pro, t_vm *vm)
{
	short	addr;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	addr = num_at_reg(*vm, pro->pc + 1, 2);
	if (pro->carry)
		increment_pc(addr % IDX_MOD, pro, vm);
	else
		goto_next_operation(pro, vm, op_s);
}

void	ft_ldi(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	a = (short)p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[pro->pc + 1], 0) == IND_CODE)
		a = (short)num_at_reg(*vm, (pro->pc + p[0]) % IDX_MOD, IND_SIZE);
	b = (short)p[1];
	if (param_type(vm->reg[pro->pc + 1], 1) == REG_CODE)
		b = pro->reg[p[1]];
	pro->reg[p[2]] = num_at_reg(*vm, pro->pc + ((a + b) % IDX_MOD), 2);
	goto_next_operation(pro, vm, op_s);
}

void	ft_sti(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	a = (short)p[1];
	if (param_type(vm->reg[pro->pc + 1], 1) == REG_CODE)
		a = pro->reg[p[1]];
	else if (param_type(vm->reg[pro->pc + 1], 1) == IND_CODE)
		a = (short)num_at_reg(*vm, (pro->pc + p[1]) % IDX_MOD, IND_SIZE);
	b = (short)p[2];
	if (param_type(vm->reg[pro->pc + 1], 2) == REG_CODE)
		b = pro->reg[p[2]];
	set_num_at_reg(vm, *pro, pro->pc + ((a + b) % IDX_MOD), pro->reg[p[0]]);
	goto_next_operation(pro, vm, op_s);
}

void	ft_fork(t_pro *pro, t_vm *vm)
{
	short	addr;
	t_pro	*new;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	addr = num_at_reg(*vm, pro->pc + 1, 2);
	if (!(new = new_pro_from_pro(*pro, *vm)))
		return ;
	new->pc = ft_mod(pro->pc + (addr % IDX_MOD), MEM_SIZE);
	new->last_pc = new->pc;
	new->cycles = vm->op_tab[vm->reg[new->pc] - 1].cycles;
	need_pro_display(vm);
	if (!(vm->pro = realloc(vm->pro, sizeof(t_pro) * (vm->nbr_pro + 1))))
		return ;
	vm->pro[vm->nbr_pro] = new;
	vm->nbr_pro++;
	goto_next_operation(pro, vm, op_s);
}

void	ft_lld(t_pro *pro, t_vm *vm)
{
	int				p[3];
	unsigned int	a;
	int				op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == IND_CODE)
		a = (short)num_at_reg(*vm, pro->pc + p[0], IND_SIZE);
	pro->reg[p[1]] = a;
	pro->carry = 0;
	if (!a)
		pro->carry = 1;
	goto_next_operation(pro, vm, op_s);
}

void	ft_lldi(t_pro *pro, t_vm *vm)
{
	int		p[3];
	int		a;
	int		b;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	a = (short)p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == REG_CODE)
		a = pro->reg[p[0]];
	else if (param_type(vm->reg[pro->pc + 1], 0) == IND_CODE)
		a = (short)num_at_reg(*vm, (pro->pc + p[0]), IND_SIZE);
	b = (short)p[1];
	if (param_type(vm->reg[pro->pc + 1], 1) == REG_CODE)
		b = pro->reg[p[1]];
	pro->carry = 0;
	if (!(a + b))
		pro->carry = 1;
	pro->reg[p[2]] = num_at_reg(*vm, pro->pc + ((a + b)), REG_SIZE);
	goto_next_operation(pro, vm, op_s);
}

void	ft_lfork(t_pro *pro, t_vm *vm)
{
	short	addr;
	t_pro	*new;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	addr = num_at_reg(*vm, pro->pc + 1, 2);
	if (!(new = new_pro_from_pro(*pro, *vm)))
		return ;
	new->pc = ft_mod(pro->pc + addr, MEM_SIZE);
	new->last_pc = new->pc;
	new->cycles = vm->op_tab[vm->reg[new->pc] - 1].cycles;
	need_pro_display(vm);
	if (!(vm->pro = realloc(vm->pro, sizeof(t_pro) * (vm->nbr_pro + 1))))
		return ;
	vm->pro[vm->nbr_pro] = new;
	vm->nbr_pro++;
	goto_next_operation(pro, vm, op_s);
}

void	ft_aff(t_pro *pro, t_vm *vm)
{
	int		p[3];
	char	c;
	int		op_s;

	op_s = op_size(vm->reg[pro->pc], vm->reg[pro->pc + 1], *vm);
	if (!(params(*pro, *vm, p)))
		return ;
	c = p[0] % 256;
	write(1, &c, 1);
	goto_next_operation(pro, vm, op_s);
}
