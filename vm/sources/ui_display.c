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

static void		set_reg_coord(t_vm vm, int reg_pos, int *x, int *y)
{
	*y = (reg_pos / 64) + 1;
	*x = ((reg_pos % 64) * 3) + 1;
}

void			ui_draw_reg(t_vm *vm, int color, int reg_pos, int inverted)
{
	WINDOW	*reg_win;
	int		x;
	int		y;

	reg_win = vm->ui->reg_win->win;
	set_reg_coord(*vm, reg_pos, &x, &y);
	wmove(reg_win, y, x);
	vm->ui->colors[reg_pos] = color;
	color = inverted ? color + vm->nbr_champs + 1 : color;
	wattron(reg_win, COLOR_PAIR(color));
	wprintw(reg_win, "%02x", vm->reg[reg_pos]);
	wattroff(reg_win, COLOR_PAIR(color));
}

void			ui_display_pro(t_vm *vm)
{
	int		i;

	i = -1;
	while (++i < vm->nbr_pro)
		if (vm->pro[i])
			ui_draw_reg(vm, vm->ui->colors[vm->pro[i]->last_pc],
			vm->pro[i]->last_pc, 0);
	i = -1;
	while (++i < vm->nbr_pro)
		if (vm->pro[i])
			ui_draw_reg(vm, vm->ui->colors[vm->pro[i]->pc], vm->pro[i]->pc, 1);
	wrefresh(vm->ui->reg_win->win);
}

void			ui_display_reg(t_vm *vm)
{
	WINDOW	*reg_win;
	int		i;
	int		j;

	reg_win = vm->ui->reg_win->win;
	wmove(reg_win, 1, 1);
	i = -1;
	while (++i < MEM_SIZE)
		ui_draw_reg(vm, 1, i, 0);
	j = -1;
	while (++j < vm->nbr_champs)
	{
		i = -1;
		while (++i < vm->champs[j]->size)
			ui_draw_reg(vm, vm->champs[j]->color, vm->champs[j]->pc + i, 0);
	}
	wrefresh(vm->ui->reg_win->win);
}
