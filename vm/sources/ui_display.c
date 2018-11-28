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

void	display_reg(t_vm vm, t_champ *champ, int reg_pos)
{
	WINDOW	*reg_win;
	int		x;
	int		y;

	reg_win = vm.ui->reg_win->win;
	y = (reg_pos / 64) + 1;
	x = ((reg_pos % 64) * 3) + 1;
	wmove(reg_win, y, x);
	if (champ)
		wattron(reg_win, COLOR_PAIR(champ->color));
	wprintw(reg_win, "%02x", vm.reg[reg_pos]);
	if (champ)
		wattroff(reg_win, COLOR_PAIR(champ->color));
	wrefresh(reg_win);
}

void	print_vm_win(t_vm vm)
{
	WINDOW	*reg_win;
	int		i;
	int		j;

	reg_win = vm.ui->reg_win->win;
	wmove(reg_win, 1, 1);
	i = -1;
	while (++i < MEM_SIZE)
		display_reg(vm, NULL, i);
	j = -1;
	while (++j < vm.nbr_champs)
	{
		i = -1;
		while (++i < vm.champs[j]->size)
			display_reg(vm, vm.champs[j], vm.champs[j]->pc + i);
	}
}
