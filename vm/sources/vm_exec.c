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

void			free_vm(t_vm *vm, int ui)
{
	free_pro(vm);
	free(vm->op_tab);
	if (vm->use_ui && ui)
	{
		free(vm->ui->reg_win);
		free(vm->ui->info_win);
		free(vm->ui);
	}
}

static void		change_values_if_needed(t_vm *vm)
{
	int		i;

	i = -1;
	while (++i < vm->nbr_champs)
	{
		vm->champs[i].cur_live = 0;
		need_champ_display(vm);
	}
	if (vm->total_live >= NBR_LIVE)
	{
		vm->max_checks = MAX_CHECKS;
		vm->cycle_to_die = vm->cycle_to_die - CYCLE_DELTA;
	}
	else if (vm->max_checks > 0)
		vm->max_checks -= 1;
	else
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->max_checks = MAX_CHECKS;
	}
	vm->total_live = 0;
}

static void		run_cycles(t_vm *vm)
{
	register int		i;
	register int		j;

	i = -1;
	while (++i < vm->cycle_to_die)
	{
		if (!vm->use_ui && vm->cycles_total == vm->dump
			&& !(i + 1 == vm->cycle_to_die && !have_active_pro(vm)))
			print_vm(*vm);
		wait_key_event(vm);
		(vm->cycles_total)++;
		j = vm->nbr_pro;
		while (--j >= 0)
		{
			if (!vm->pro[j])
				continue ;
			if (vm->pro[j]->op_code == NEW_OP)
				new_op(vm->pro[j], vm);
			if (vm->pro[j]->cycles > 1)
				vm->pro[j]->cycles -= 1;
			else
				exec_pro(vm->pro[j], vm);
		}
		ui_update_if_needed(vm);
	}
}

int				exec_vm(t_vm *vm)
{
	int		i;

	i = -1;
	if (!init_process(vm))
		return (0);
	if (!init_ui(vm))
	{
		endwin();
		return (0);
	}
	while (1)
	{
		ui_update_if_needed(vm);
		run_cycles(vm);
		if (!have_active_pro(vm))
			break ;
		change_values_if_needed(vm);
	}
	if (vm->use_ui)
		ui_display_winner(*vm);
	else
		ft_printf(WIN_TXT, -winner(*vm).player, winner(*vm).name);
	free_vm(vm, 1);
	endwin();
	return (1);
}

void			print_vm(t_vm vm)
{
	int		i;
	int		j;

	if (vm.use_ui)
		return ;
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0 && i > 0)
			ft_printf("\n");
		if (i % 64 == 0 && i == 0)
			ft_printf("0x0000 : ");
		else if (i % 64 == 0)
			ft_printf("%#06x : ", i);
		ft_printf("%02x ", vm.reg[i]);
	}
	ft_printf("\n");
	free_vm(&vm, 1);
	exit(0);
}
