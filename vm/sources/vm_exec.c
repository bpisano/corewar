/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_exec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 18:03:29 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 23:43:30 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void		free_vm(t_vm *vm)
{
	int		i;

	i = -1;
	while (++i < MAX_PLAYERS)
		ft_memdel((void **)&(vm->champs[i]));
	free_pro(vm);
	free(vm->op_tab);
	if (vm->use_ui)
	{
		free(vm->ui->reg_win);
		free(vm->ui->info_win);
		free(vm->ui);
	}
}

static void		change_values_if_needed(t_vm *vm)
{
	int		i;
	int		lives;

	i = -1;
	lives = 0;
	while (vm->champs[++i])
	{
		lives += vm->champs[i]->cur_live;
		vm->champs[i]->last_live = vm->champs[i]->cur_live;
		vm->champs[i]->cur_live = 0;
		need_champ_display(vm);
	}
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
	int		number_of_pro;

	i = -1;
	while (++i < vm->cycle_to_die)
	{
		vm->cycles_total++;
		j = -1;
		number_of_pro = vm->nbr_pro;
		while (++j < number_of_pro)
			if (!vm->pro[j])
				continue ;
			else if (vm->pro[j]->cycles > 1)
				vm->pro[j]->cycles -= 1;
			else
				exec_pro(vm->pro[j], vm);
		getch();
		ui_update_if_needed(vm);
		//if (vm->cycles_total == 1101)
			//print_vm(*vm);
	}
}

int				exec_vm(t_vm *vm)
{
	int		i;

	i = -1;
	if (!init_process(vm))
		return (0);
	if (!init_ui(vm))
		return (0);
	while (1)
	{
		run_cycles(vm);
		if (!have_active_pro(vm))
			break ;
		change_values_if_needed(vm);
	}
	print_vm(*vm);
	printf("Winner : %s\n", winner(*vm)->name);
	free_vm(vm);
	end_ui();
	return (1);
}

void			print_vm(t_vm vm)
{/*
	int		i;
	int		j;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0 && i > 0)
			printf("\n");
		printf("%#04x ", vm.reg[i]);
	}
	printf("\n----------------------------------\n");
	printf("VM\n\tcycle_to_die : %d\n\tcycle_delta : %d\n\tnbr_live : %d\n\tmax_check : %d\n\tcurrent_cycle : %d\n\tnbr process : %d\n\n", vm.cycle_to_die, CYCLE_DELTA, NBR_LIVE, vm.max_checks, vm.cycles_total, vm.number_of_pro);
	i = -1;
	while (vm.champs[++i])
		printf("CHAMP : %s\n\tplayer : %u\n\tcurr_live : %d\n\n", vm.champs[i]->name, vm.champs[i]->player, vm.champs[i]->cur_live);
	i = -1;
	if (vm.pro == NULL)
		return ;
	while (++i < vm.number_of_pro)
	{
		if (vm.pro[i])
			printf("PRO : %d\n\tplayer : %u\n\tpc : %d\n\toperation_cycle : %d\n\tlives : %d\n\n", i, vm.pro[i]->player, vm.pro[i]->pc, vm.pro[i]->cycles, vm.pro[i]->live);
		else
			printf("PRO : %d doesnt exist anymore\n\n", i);
	}
	printf("----------------------------------\n");*/
}
