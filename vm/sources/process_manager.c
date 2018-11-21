/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_manager.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 14:48:54 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

t_pro	*new_pro_from_champ(t_champ champ, t_vm vm)
{
	t_pro	*new;
	int		op_code;
	int		i;

	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	op_code = vm.reg[champ.pc] - 1;
	new->id = number_of_pro(vm);
	new->player = champ.player;
	new->active = 1;
	new->pc = champ.pc;
	new->cycles = op_code < 16 ? vm.op_tab[op_code].cycles : 0;
	new->live = 0;
	new->carry = 0;
	i = -1;
	while (++i < REG_NUMBER)
		new->reg[i] = 0;
	new->reg[1] = champ.player;
	return (new);
}

t_pro	*new_pro_from_pro(t_pro pro, t_vm vm)
{
	t_pro	*new;

	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	new->id = number_of_pro(vm);
	new->player = pro.player;
	new->pc = pro.pc;
	new->cycles = pro.cycles;
	new->active = pro.active;
	new->live = pro.live;
	new->carry = pro.carry;
	ft_memcpy(new->reg, pro.reg, REG_NUMBER);
	return (new);
}

void	free_pro(t_vm *vm)
{
	int		i;

	i = -1;
	while (vm->pro[++i])
		free(vm->pro[i]);
	free(vm->pro);
}

void	increment_pc(int increment, t_pro *pro)
{
	if (pro->pc + increment >= MEM_SIZE)
	{
		pro->pc = (increment + pro->pc) % MEM_SIZE;
		return ;
	}
	else if (pro->pc + increment < 0)
	{
		pro->pc = (increment + pro-> pc) % MEM_SIZE;
		if (pro->pc != 0)
			pro->pc += MEM_SIZE;
		return ;
	}
	pro->pc += increment;
}

void	goto_next_operation(t_pro *pro, t_vm vm)
{
	int		op_code;
	int		op_s;

	op_code = vm.reg[pro->pc];
	if (op_code > 15 || op_code < 1)
		op_s = 0;
	else if (op_code == 1 || op_code == 9 || op_code == 12 || op_code == 15)
		op_s = vm.op_tab[op_code].dir_size;
	else
		op_s = op_size(op_code, vm.reg[pro->pc + 1], vm);
	increment_pc(op_s + 1, pro);
	op_code = vm.reg[pro->pc];
	pro->cycles = 0;
	if (op_code <= 15 && op_code >= 1)
		pro->cycles = vm.op_tab[op_code - 1].cycles;
}
