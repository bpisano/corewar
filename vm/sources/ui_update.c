/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_update.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 13:41:59 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ui_update_reg(t_vm *vm, t_pro pro, int reg_pos)
{
	int		i;
	int		inverted;

	if (!vm->use_ui)
		return ;
	i = -1;
	inverted = 0;
	while (++i < vm->nbr_pro)
	{
		if (!vm->pro[i])
			continue ;
		if (vm->pro[i]->pc == reg_pos)
		{
			inverted = 1;
			break ;
		}
	}
	vm->ui->bold[reg_pos] = 50;
	ui_draw_reg(vm, pro.color, reg_pos, inverted);
}

void	ui_update_info(t_vm vm)
{
	ui_print_right_center(vm.ui->info_win, INFO_LINE + 2, "%d",
							vm.cycles_total);
	ui_print_right_center(vm.ui->info_win, INFO_LINE + 4, "         ");
	if (vm.cycle_to_die > 0)
		ui_print_right_center(vm.ui->info_win, INFO_LINE + 4, "%d",
								vm.cycle_to_die);
	else
		ui_print_right_center(vm.ui->info_win, INFO_LINE + 4, "0");
	ui_print_right_center(vm.ui->info_win, INFO_LINE + 5, "%d", CYCLE_DELTA);
	ui_print_right_center(vm.ui->info_win, INFO_LINE + 6, "%d", NBR_LIVE);
	ui_print_right_center(vm.ui->info_win, INFO_LINE + 7, "%d", MAX_CHECKS);
	ui_print_right_center(vm.ui->info_win, INFO_LINE + 9, "         ");
	ui_print_right_center(vm.ui->info_win, INFO_LINE + 9, "%d",
							vm.nbr_pro_alive);
}

void	ui_update_champs(t_vm vm)
{
	int		i;
	int		offset;

	i = -1;
	while (++i < vm.nbr_champs)
	{
		offset = i * 5 + CHAMPS_LINE;
		wattron(vm.ui->info_win->win, COLOR_PAIR(vm.champs[i].color));
		if (ft_strlen(vm.champs[i].name) <= 18)
			ui_print_right_center(vm.ui->info_win, offset + 2, "%s",
								vm.champs[i].name);
		else
			ui_print_right_center(vm.ui->info_win, offset + 2, "%.15s...",
								vm.champs[i].name);
		wattroff(vm.ui->info_win->win, COLOR_PAIR(vm.champs[i].color));
		ui_print_right_center(vm.ui->info_win, offset + 3, "%d",
								vm.champs[i].player * -1);
		ui_print_right_center(vm.ui->info_win, offset + 4, "         ");
		ui_print_right_center(vm.ui->info_win, offset + 5, "         ");
		ui_print_right_center(vm.ui->info_win, offset + 4, "%d",
								vm.champs[i].cur_live);
		ui_print_right_center(vm.ui->info_win, offset + 5, "%d",
								vm.champs[i].last_live);
	}
}

void	ui_update_if_needed(t_vm *vm)
{
	if (!vm->use_ui)
		return ;
	if (vm->ui->need_pro_disp)
	{
		ui_display_pro(vm);
		wrefresh(vm->ui->reg_win->win);
	}
	if (vm->ui->need_cha_disp)
		ui_update_champs(*vm);
	ui_update_info(*vm);
	ui_update_reg_bold(vm);
	wrefresh(vm->ui->info_win->win);
	vm->ui->need_pro_disp = 0;
	vm->ui->need_cha_disp = 0;
}

void	ui_update_settings(t_vm vm)
{
	if (!vm.use_ui)
		return ;
	ui_print_right_center(vm.ui->info_win, SETTINGS_LINE + 2, "         ");
	ui_print_right_center(vm.ui->info_win, SETTINGS_LINE + 2, "%d",
							vm.ui->cycle_sec);
	wrefresh(vm.ui->info_win->win);
}
