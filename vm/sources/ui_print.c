/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 14:48:54 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ui_print_left_center(t_win *w, int line, int len, char *f, ...)
{
	va_list		args;

	va_start(args, f);
	wmove(w->win, line, w->width / 2 - len);
	wprintw(w->win, f, va_arg(args, void *));
	va_end(args);
}

void	ui_print_right_center(t_win *w, int line, char *f, ...)
{
	va_list		args;

	va_start(args, f);
	wmove(w->win, line, w->width / 2 + 1);
	wprintw(w->win, f, va_arg(args, void *));
	va_end(args);
}

void	ui_print_title(t_win *w, int line, char *f, ...)
{
	va_list		args;
	int			i;
	int			left_offset;

	va_start(args, f);
	left_offset = 5;
	wmove(w->win, line, 1);
	i = -1;
	while (++i < w->width - 2)
		wprintw(w->win, "_");
	wattron(w->win, A_BOLD);
	mvwprintw(w->win, line, left_offset, f, va_arg(args, void *));
	wattroff(w->win, A_BOLD);
	va_end(args);
}
