/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_manager.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 16:43:05 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

t_pro	*new_pro_from_champ(t_champ champ, t_vm vm)
{
	t_pro	*new;
	int		op_code;

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
	return (new);
}

t_pro	*new_pro_from_pro(t_pro pro, int dir, t_vm vm)
{
	t_pro	*new;

	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	new->id = number_of_pro(vm);
	new->player = pro.player;
	new->pc = pro.pc + (dir % IDX_MOD);
	new->active = pro.active;
	new->live = pro.live;
	new->carry = pro.carry;
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
		pro->pc = increment - (MEM_SIZE - pro->pc);
		return;
	}
	pro->pc += increment;
}

void	goto_next_operation(t_pro *pro)
{
	
}
