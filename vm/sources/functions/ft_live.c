/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_live.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 22:59:14 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 22:59:21 by bpisano     ###    #+. /#+    ###.fr     */
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
			if (!vm->use_ui)
				ft_printf(LIVE_TXT, -vm->champs[i].player, vm->champs[i].name);
			break ;
		}
	}
	goto_next_operation(pro, vm);
}
