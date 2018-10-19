/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_creator.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 16:07:50 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 16:08:09 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

t_pro	*new_pro_from_champ(t_champ champ, t_vm vm)
{
	t_pro	*new;

	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	new->id = number_of_pro(vm) + 1;
	new->player = champ.player;
	new->pc = champ.pc;
	new->live = 0;
	new->carry = 0;
	return (new);
}

t_pro	*new_pro_from_pro(t_pro pro, int dir, t_vm vm)
{
	t_pro	*new;

	if (!(new = (t_pro *)malloc(sizeof(t_pro))))
		return (NULL);
	new->id = number_of_pro(vm) + 1;
	new->player = pro.player;
	new->pc = pro.pc + (dir % IDX_MOD);
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
