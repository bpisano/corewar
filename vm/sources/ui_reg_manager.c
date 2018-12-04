/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_reg_manager.c                                 .::    .:/ .      .::   */
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
	*y = ((reg_pos % MEM_SIZE) / 64) + 1;
	*x = (((reg_pos % MEM_SIZE) % 64) * 3) + 1;
}

void			ui_draw_reg(t_vm *vm, int color, int reg_pos, int inverted)
{
	WINDOW	*reg_win;
	int		x;
	int		y;

	if (!vm->use_ui)
		return ;
	reg_win = vm->ui->reg_win->win;
	set_reg_coord(*vm, reg_pos, &x, &y);
	wmove(reg_win, y, x);
	vm->ui->colors[reg_pos] = color;
	color = inverted ? color + vm->nbr_champs + 1 : color;
	wattron(reg_win, COLOR_PAIR(color));
	wprintw(reg_win, "%02x", vm->reg[reg_pos]);
	wattroff(reg_win, COLOR_PAIR(color));
}

void			ui_die_pro(t_vm *vm, t_pro *pro, int pro_index)
{
	int		i;

	if (!vm->use_ui)
		return ;
	i = -1;
	while (++i < vm->nbr_pro)
	{
		if (!vm->pro[i])
			continue ;
		if (i != pro_index && vm->pro[i]->pc == pro->pc)
			return ;
	}
	ui_draw_reg(vm, vm->ui->colors[pro->pc], pro->pc, 0);
}
