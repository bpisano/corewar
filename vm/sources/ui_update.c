/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_update.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 14:48:54 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ui_update_pro_if_needed(t_vm *vm)
{
	if (vm->ui->need_pro_disp)
		ui_display_pro(vm);
	vm->ui->need_pro_disp = 0;
}

void	ui_update_reg(t_vm *vm, t_pro pro, int reg_pos)
{
	int		i;
	int		inverted;

	i = -1;
	inverted = 0;
	while (++i < vm->nbr_pro)
	{
		if (vm->pro[i]->pc == reg_pos)
		{
			inverted = 1;
			break ;
		}
	}
	ui_draw_reg(vm, pro.color, reg_pos, inverted);
}

void	ui_update_info(t_vm vm)
{
	ui_print_right_center(vm.ui->info_win, 4, "%d", vm.cycles_total);
	ui_print_right_center(vm.ui->info_win, 6, "%d", vm.cycle_to_die);
	ui_print_right_center(vm.ui->info_win, 7, "%d", CYCLE_DELTA);
	ui_print_right_center(vm.ui->info_win, 8, "%d", NBR_LIVE);
	ui_print_right_center(vm.ui->info_win, 9, "%d", MAX_CHECKS);
	wrefresh(vm.ui->info_win->win);
}
