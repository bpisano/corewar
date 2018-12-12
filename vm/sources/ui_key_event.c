/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_key_event.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 14:48:54 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

static void		set_unpause(t_vm *vm)
{
	ui_display_run_title(*vm);
	vm->ui->paused = 0;
}

static void		set_pause(t_vm *vm)
{
	ui_display_pause_title(*vm);
	vm->ui->paused = 1;
}

static void		increment_cycle_sec(t_vm *vm, int increment)
{
	if (vm->ui->cycle_sec + increment <= 0)
		vm->ui->cycle_sec = 1;
	else if (vm->ui->cycle_sec + increment >= 1000)
		vm->ui->cycle_sec = 1000;
	else
		vm->ui->cycle_sec += increment;
	ui_update_settings(*vm);
}

void			wait_key_event(t_vm *vm)
{
	char	c;

	if (!vm->use_ui)
		return ;
	timeout(1000 / vm->ui->cycle_sec);
	while (1)
	{
		c = getch();
		if (vm->ui->paused && c < 0)
			continue ;
		else if (!vm->ui->paused && c < 0)
			break ;
		else if (c == ' ' && vm->ui->paused)
			set_unpause(vm);
		else if (c == ' ' && !vm->ui->paused)
			set_pause(vm);
		else if (c == 'e')
			increment_cycle_sec(vm, 1);
		else if (c == 'w')
			increment_cycle_sec(vm, -1);
		else if (c == 'r')
			increment_cycle_sec(vm, 10);
		else if (c == 'q')
			increment_cycle_sec(vm, -10);
		else if (c == 's')
			break ;
	}
}
