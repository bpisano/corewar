/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_exec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 15:00:50 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 16:38:13 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

static void		change_values_if_needed(t_vm *vm)
{
	int		i;
	int		lives;
	
	i = -1;
	lives = 0;
	while (vm->champs[++i])
		lives += vm->champs[++i]->cur_live;
	if (lives >= NBR_LIVE)
		vm->cycle_to_die -= CYCLE_DELTA;
	if (vm->max_checks > 0)
		vm->max_checks -= 1;
	else
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->max_checks = MAX_CHECKS;
	}
}

static void		run_cycles(t_vm *vm)
{
	int		i;
	
	i = -1;
	while (++i < vm->cycle_to_die)
		;//exec_pro(vm->pro);
}

int				exec_vm(t_vm *vm)
{
	int		i;
	
	if (!init_process(vm))
		return (0);
	i = -1;
	while (!have_winner(*vm))
	{
		run_cycles(vm);
		change_values_if_needed(vm);
	}
	return (1);
}
