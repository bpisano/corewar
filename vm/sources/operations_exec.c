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

void	live(t_pro *pro, t_vm *vm)
{
	int		champ;
	int		i;
	
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
	increment_pc(5, pro);
}
