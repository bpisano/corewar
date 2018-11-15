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

void	ft_live(t_pro *pro, t_vm *vm)
{
	unsigned int	champ;
	int				i;
	
	champ = num_at_reg(*vm, pro->pc + 1, 4);
	i = -1;
	while (vm->champs[++i])
	{
		if (vm->champs[i]->player == champ)
		{
			vm->champs[i]->cur_live += 1;
			break ;
		}
	}
	goto_next_operation(pro, *vm);
}

void	ft_ld(t_pro *pro, t_vm *vm)
{
	int		*p;
	unsigned int		a;
	
	if (!(p = params(*pro, *vm)))
		return ;
	a = p[0] % IDX_MOD;
	if (param_type(vm->reg[pro->pc + 1], 0) == IND_CODE)
		a = num_at_reg(*vm, p[0] % IDX_MOD, REG_SIZE);
	pro->reg[p[1]] = a;
	pro->carry = 1;
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_st(t_pro *pro, t_vm *vm)
{
	int		*p;
	int		a;

	if (!(p = params(*pro, *vm)))
		return ;
		a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == 1)
		a = pro->reg[p[0]];
	if (param_type(vm->reg[pro->pc + 1], 1) == 1)
		pro->reg[p[1]] = a;
	else
		set_num_at_reg(vm, pro->pc + (p[1] % IDX_MOD), a);
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_add(t_pro *pro, t_vm *vm)
{
	int		*p;

	if (!(p = params(*pro, *vm)))
		return ;
	pro->reg[p[2]] = pro->reg[p[0]] + pro->reg[p[1]];
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_sub(t_pro *pro, t_vm *vm)
{
	int		*p;

	if (!(p = params(*pro, *vm)))
		return ;
	pro->reg[p[2]] = p[0] - p[1];
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_and(t_pro *pro, t_vm *vm)
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

void	ft_or(t_pro *pro, t_vm *vm)
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

void	ft_xor(t_pro *pro, t_vm *vm)
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

void	ft_zjmp(t_pro *pro, t_vm *vm)
{
	int		addr;

	addr = num_at_reg(*vm, pro->pc + 1, 4);
	if (pro->carry)
		increment_pc(addr % IDX_MOD, pro);
	else
		goto_next_operation(pro, *vm);
}

void	ft_ldi(t_pro *pro, t_vm *vm)
{
	int		*p;
	int		a;
	int		b;

	if (!(p = params(*pro, *vm)))
		return ;
	a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == 1)
		a = pro->reg[p[0]];
	b = p[1];
	if (param_type(vm->reg[pro->pc + 1], 1) == 1)
		b = pro->reg[p[1]];
	pro->reg[p[2]] = num_at_reg(*vm, pro->pc + ((a + b) % IDX_MOD), REG_SIZE);
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_sti(t_pro *pro, t_vm *vm)
{
	int		*p;
	int		a;
	int		b;

	if (!(p = params(*pro, *vm)))
		return ;
	if (param_type(vm->reg[pro->pc + 1], 1) == 1)
		a = pro->reg[p[1]];
	else
		a = p[1];
	if (param_type(vm->reg[pro->pc + 1], 2) == 1)
		b = pro->reg[p[2]];
	else
		b = p[2];
	set_num_at_reg(vm, pro->pc + ((a + b) % IDX_MOD), pro->reg[p[0]]);
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_fork(t_pro *pro, t_vm *vm)
{
	int		*p;
	t_pro	*new;

	if (!(p = params(*pro, *vm)))
		return ;
	new = new_pro_from_pro(*pro, *vm);
	new->pc = (new->pc + p[0]) % IDX_MOD;
	new->cycles = vm->op_tab[new->pc - 1].cycles;
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_lld(t_pro *pro, t_vm *vm)
{
	int		*p;
	
	if (!(p = params(*pro, *vm)))
		return ;
	pro->reg[p[1]] = p[0];
	pro->carry = 1;
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_lldi(t_pro *pro, t_vm *vm)
{
	int		*p;
	int		a;
	int		b;

	if (!(p = params(*pro, *vm)))
		return ;
	a = p[0];
	if (param_type(vm->reg[pro->pc + 1], 0) == 1)
		a = pro->reg[p[0]];
	b = p[1];
	if (param_type(vm->reg[pro->pc + 1], 1) == 1)
		b = pro->reg[p[1]];
	pro->reg[p[2]] = num_at_reg(*vm, pro->pc + a + b, REG_SIZE);
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_lfork(t_pro *pro, t_vm *vm)
{
	int		*p;
	t_pro	*new;

	if (!(p = params(*pro, *vm)))
		return ;
	new = new_pro_from_pro(*pro, *vm);
	new->pc = (new->pc + p[0]);
	new->cycles = vm->op_tab[new->pc - 1].cycles;
	free(p);
	goto_next_operation(pro, *vm);
}

void	ft_aff(t_pro *pro, t_vm *vm)
{
	int		*p;
	char	c;

	if (!(p = params(*pro, *vm)))
		return ;
	c = p[0] % 256;
	write(1, &c, 1);
	free(p);
	goto_next_operation(pro, *vm);
}
