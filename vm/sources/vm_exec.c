/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_exec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 18:03:29 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 17:07:25 by bpisano     ###    #+. /#+    ###.fr     */
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
		lives += vm->champs[i]->cur_live;
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
	int		j;
	
	i = -1;
	while (++i < vm->cycle_to_die)
	{
		j = -1;
		while (vm->pro[++j])
		{
			if (vm->pro[j]->cycles > 0)
			{
				vm->pro[j]->cycles -= 1;
				continue ;
			}
			exec_pro(vm->pro[j], vm);
		}
		vm->cycle_to_die -= 1;
		print_vm(*vm);
		sleep(1);
	}
}

int				exec_vm(t_vm *vm)
{
	int		i;
	
	if (!init_process(vm))
		return (0);
	i = -1;
	print_vm(*vm);
	while (1)
	{
		run_cycles(vm);
		if (have_winner(*vm))
				break ;
		change_values_if_needed(vm);
	}
	printf("end");
	return (1);
}

void			print_vm(t_vm vm)
{
	int		i;
	int		j;

	i = -1;
	while(++i < MEM_SIZE)
	{
		if (i % 64 == 0 && i > 0)
			printf("\n");
		printf("%#04x ", vm.reg[i]);
	}
	printf("----------------------------------\n");
	printf("VM\n\tcycle_to_die : %d\n\tcycle_delta : %d\n\tnbr_live : %d\n\tmax_check : %d\n\n", vm.cycle_to_die, CYCLE_DELTA, NBR_LIVE, vm.max_checks);
	i = -1;
	while (vm.champs[++i])
		printf("CHAMP : %s\n\tplayer : %u\n\tcurr_live : %d\n\n", vm.champs[i]->name, vm.champs[i]->player, vm.champs[i]->cur_live);
	i = -1;
	if (vm.pro == NULL)
		return ;
	while (vm.pro[++i])
		printf("PRO : %d\n\tplayer : %d\n\tpc : %d\n\toperation_cycle : %d\n\n", vm.pro[i]->id, vm.pro[i]->player, vm.pro[i]->pc, vm.pro[i]->cycles);
}
