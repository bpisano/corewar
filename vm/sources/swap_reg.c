/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap_reg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/21 15:16:52 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:19:56 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	swap_reg(t_vm *vm, unsigned int c)
{
	int				i;
	int				max;
	unsigned char	swp;

	max = CHAMP_MAX_SIZE;
	i = -1;
	while (++i < max)
	{
		swp = vm->reg[vm->champs[c].pc + i];
		vm->reg[vm->champs[c].pc + i] = vm->reg[vm->champs[c + 1].pc + i];
		vm->reg[vm->champs[c + 1].pc + i] = swp;
	}
}
