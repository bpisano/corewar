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

static int		is_inverted(t_vm vm, int reg_pos)
{
	return (vm.ui->inverted[reg_pos % MEM_SIZE]);
}

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
	vm->ui->colors[reg_pos % MEM_SIZE] = color;
	color = inverted ? color + vm->nbr_champs + 1 : color;
	wattron(reg_win, COLOR_PAIR(color));
	if (vm->ui->bold[reg_pos % MEM_SIZE] > 0)
		wattron(reg_win, COLOR_PAIR(color) | A_BOLD);
	wprintw(reg_win, "%02x", vm->reg[reg_pos % MEM_SIZE]);
	wattroff(reg_win, COLOR_PAIR(color) | A_BOLD);
}

void			ui_die_pro(t_vm *vm, t_pro *pro)
{
	if (!vm->use_ui)
		return ;
	if (is_inverted(*vm, pro->pc))
		return ;
	ui_draw_reg(vm, vm->ui->colors[pro->pc], pro->pc, 0);
}

void			ui_update_reg_bold(t_vm *vm)
{
	register int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (vm->ui->bold[i] == 1)
		{
			vm->ui->bold[i] = 0;
			ui_draw_reg(vm, vm->ui->colors[i], i, is_inverted(*vm, i));
		}
		else
			vm->ui->bold[i] = vm->ui->bold[i] - 1;
	}
}
