/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 14:48:54 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ui_display_pro(t_vm *vm)
{
	int		i;

	ft_memset(vm->ui->inverted, 0, sizeof(char) * MEM_SIZE);
	i = -1;
	while (++i < vm->nbr_pro)
		if (vm->pro[i])
			ui_draw_reg(vm, vm->ui->colors[vm->pro[i]->last_pc],
			vm->pro[i]->last_pc, 0);
	i = -1;
	while (++i < vm->nbr_pro)
		if (vm->pro[i])
		{
			vm->ui->inverted[vm->pro[i]->pc] += 1;
			ui_draw_reg(vm, vm->ui->colors[vm->pro[i]->pc], vm->pro[i]->pc, 1);
		}
	wrefresh(vm->ui->reg_win->win);
}

void	ui_display_reg(t_vm *vm)
{
	int		i;
	int		j;

	WINDOW * reg_win;
	reg_win = vm->ui->reg_win->win;
	wmove(reg_win, 1, 1);
	i = -1;
	while (++i < MEM_SIZE)
		ui_draw_reg(vm, 1, i, 0);
	j = -1;
	while (++j < vm->nbr_champs)
	{
		i = -1;
		while (++i < vm->champs[j].size)
			ui_draw_reg(vm, vm->champs[j].color, vm->champs[j].pc + i, 0);
	}
	wrefresh(vm->ui->reg_win->win);
}

void	ui_display_infos(t_vm vm)
{
	ui_print_title(vm.ui->info_win, INFO_LINE, "INFOS");
	wattron(vm.ui->info_win->win, COLOR_PAIR(1));
	ui_print_left_center(vm.ui->info_win, INFO_LINE + 2, 6, "CYCLES ");
	ui_print_left_center(vm.ui->info_win, INFO_LINE + 4, 13, "CYCLES_TO_DIE ");
	ui_print_left_center(vm.ui->info_win, INFO_LINE + 5, 12, "CYCLES_DELTA ");
	ui_print_left_center(vm.ui->info_win, INFO_LINE + 6, 8, "NBR_LIVE ");
	ui_print_left_center(vm.ui->info_win, INFO_LINE + 7, 10, "MAX_CHECKS ");
	ui_print_left_center(vm.ui->info_win, INFO_LINE + 9, 9, "PROCESSES ");
	wattroff(vm.ui->info_win->win, COLOR_PAIR(1));
	ui_update_info(vm);
}

void	ui_display_champs(t_vm vm)
{
	int		i;
	int		offset;

	ui_print_title(vm.ui->info_win, CHAMPS_LINE, "PLAYERS");
	wattron(vm.ui->info_win->win, COLOR_PAIR(1));
	i = -1;
	while (++i < vm.nbr_champs)
	{
		offset = i * 5 + CHAMPS_LINE;
		ui_print_left_center(vm.ui->info_win, offset + 2, 5, "NAME ");
		ui_print_left_center(vm.ui->info_win, offset + 3, 3, "ID ");
		ui_print_left_center(vm.ui->info_win, offset + 4, 14, "CURRENT_LIVES ");
		ui_print_left_center(vm.ui->info_win, offset + 5, 11, "LAST_LIVES ");
	}
	wattroff(vm.ui->info_win->win, COLOR_PAIR(1));
	ui_update_champs(vm);
}

void	ui_display_settings(t_vm vm)
{
	ui_print_title(vm.ui->info_win, SETTINGS_LINE, "SETTINGS");
	wattron(vm.ui->info_win->win, COLOR_PAIR(1));
	ui_print_left_center(vm.ui->info_win, SETTINGS_LINE + 2, 10, "CYCLES/SEC ");
	wattroff(vm.ui->info_win->win, COLOR_PAIR(1));
	ui_update_settings(vm);
}
