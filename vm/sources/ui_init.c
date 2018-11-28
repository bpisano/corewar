/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 14:48:54 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

static t_win	*new_win(int x, int y, int width, int height)
{
	t_win	*win;

	if (!(win = (t_win *)malloc(sizeof(t_win))))
		return (NULL);
	win->x = x;
	win->y = y;
	win->width = width;
	win->height = height;
	win->win = newwin(height, width, y, x);
	box(win->win, 0, 0);
	wrefresh(win->win);
	return (win);
}

static t_ui		*new_ui()
{
	t_ui	*new;
	t_win	*win_reg;

	if (!(new = (t_ui *)malloc(sizeof(t_ui))))
		return (NULL);
	int		j = -1;
	while (++j < MEM_SIZE)
		new->colors[j] = 1;
	//ft_memset(new->colors, 1, MEM_SIZE);
	getmaxyx(stdscr, new->height, new->width);
	if (!(new->reg_win = new_win(0, 1, (MEM_SIZE / 64 * 3 - 1) + 2, 64 + 2)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}

static void		init_colors(t_vm *vm)
{
	int		i;

	start_color();
	use_default_colors();
	i = -1;
	init_color(COLOR_GRAY, 400, 400, 400);
	init_pair(1, COLOR_GRAY, -1);
	init_pair(2 + vm->nbr_champs, COLOR_BLACK, COLOR_WHITE);
	while (++i < vm->nbr_champs)
	{
		vm->champs[i]->color = i + 2;
		init_pair(i + 2, i + 1, -1);
		init_pair(i + 3 + vm->nbr_champs, COLOR_WHITE, i + 1);
	}
}

int				init_ui(t_vm *vm)
{
	initscr();
	curs_set(0);
	init_colors(vm);
	refresh();
	if (!(vm->ui = new_ui()))
		return (0);
	mvprintw(0, (vm->ui->reg_win->width - 7) / 2, "COREWAR");
	display_reg_win(vm);
	display_pro(vm);
	wrefresh(vm->ui->reg_win->win);
	return (1);
}

void			end_ui()
{
	endwin();
}