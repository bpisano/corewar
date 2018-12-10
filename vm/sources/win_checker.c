/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   win_checker.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 18:03:29 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:03:27 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

t_champ		winner(t_vm vm)
{
	int		i;
	int		live_max;
	t_champ	champ_max;

	i = -1;
	live_max = 0;
	while (++i < vm.nbr_champs)
		if (vm.champs[i].live >= live_max)
		{
			live_max = vm.champs[i].live;
			champ_max = vm.champs[i];
		}
	return (champ_max);
}

int			have_active_pro(t_vm *vm)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < vm->nbr_pro)
	{
		if (!vm->pro[i])
			continue ;
		if (!vm->pro[i]->live)
		{
			vm->nbr_pro_alive--;
			ui_die_pro(vm, vm->pro[i]);
			ft_memdel((void **)(&(vm->pro[i])));
		}
		else
		{
			vm->pro[i]->live = 0;
			j++;
		}
	}
	return (j);
}
