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

	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	op_code = vm.reg[champ.pc] - 1;
	new->player = champ.player;
	new->pc = champ.pc;
	new->last_pc = new->pc;
	new->live = 0;
	new->carry = 0;
	new->color = champ.color;
	new->op_code = NEW_OP;
	ft_memset(new->reg, 0, (REG_NUMBER + 1) * sizeof(int));
	new->reg[1] = champ.player;
	return (new);
}

t_pro	*new_pro_from_pro(t_pro pro, t_vm vm)
{
	t_pro	*new;

	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	new->player = pro.player;
	new->live = pro.live;
	new->carry = pro.carry;
	new->color = pro.color;
	ft_memcpy(new->reg, pro.reg, (REG_NUMBER + 1) * sizeof(int));
	return (new);
}

void	free_pro(t_vm *vm)
{
	int		i;

	i = -1;
	if (!vm->pro)
		return ;
	while (++i < vm->nbr_pro)
		ft_memdel((void **)&(vm->pro[i]));
	free(vm->pro);
}

void	increment_pc(int increment, t_pro *pro, t_vm *vm)
{
	pro->last_pc = pro->pc;
	pro->pc = (pro->pc + increment) % MEM_SIZE;
	if (pro->pc < 0)
		pro->pc = pro->pc + MEM_SIZE;
	need_pro_display(vm);
}

void	goto_next_operation(t_pro *pro, t_vm *vm)
{
	increment_pc(pro->op_size + 1, pro, vm);
	pro->op_code = NEW_OP;
}
