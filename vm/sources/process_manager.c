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

t_pro	*new_pro_from_champ(t_champ champ, t_vm vm, int id)
{
	t_pro	*new;
	int		op_code;
	int		i;

	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	op_code = vm.reg[champ.pc] - 1;
	new->id = id;
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
	new->live = 0;
	new->carry = 0;
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
	if (increment + pro->pc < 0)
		pro->pc = pro->pc + increment + MEM_SIZE;
	pro->pc = (pro->pc + increment) % MEM_SIZE;
}

void	goto_next_operation(t_pro *pro, t_vm vm, int op_size)
{
	int		op_code;

	pro->pc = (pro->pc + op_size + 1) % MEM_SIZE;
	op_code = vm.reg[pro->pc];
	if (op_code < 1 || op_code > 16)
		pro->cycles = 0;
	else
		pro->cycles = vm.op_tab[op_code - 1].cycles;
}
