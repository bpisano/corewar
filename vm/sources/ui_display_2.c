/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_display_2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 14:48:54 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

static void		clear_title(t_vm vm)
{
	int		i;

	i = -1;
	while (++i < vm.ui->width)
		mvprintw(0, i, " ");
}

void			ui_display_pause_title(t_vm vm)
{
	clear_title(vm);
	attron(A_BOLD | A_BLINK);
	mvprintw(0, (vm.ui->reg_win->width - 27) / 2,
	"[PAUSED] Press start to run");
	attroff(A_BOLD | A_BLINK);
}

void			ui_display_run_title(t_vm vm)
{
	clear_title(vm);
	attron(A_BOLD);
	mvprintw(0, (vm.ui->reg_win->width - 17) / 2,
	"[RUNNING] Corewar");
	attroff(A_BOLD | A_BLINK);
}
