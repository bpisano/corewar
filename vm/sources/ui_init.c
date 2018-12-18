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
	if (!(win->win = newwin(height, width, y, x)))
		return (NULL);
	box(win->win, 0, 0);
	wrefresh(win->win);
	return (win);
}

static t_ui		*new_ui(void)
{
	t_ui	*new;
	t_win	*win_reg;

	if (!(new = (t_ui *)malloc(sizeof(t_ui))))
		return (NULL);
	getmaxyx(stdscr, new->height, new->width);
	ft_memset(new->colors, 1, MEM_SIZE);
	new->need_pro_disp = 0;
	new->need_cha_disp = 0;
	new->paused = 1;
	new->cycle_sec = 50;
	if (!(new->reg_win = new_win(0, 1, (MEM_SIZE / 64 * 3 - 1) + 2, 64 + 2)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	if (!(new->info_win = new_win(new->reg_win->width, 1, 40, 64 + 2)))
	{
		ft_memdel((void **)new->reg_win);
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}

static void		init_pro_colors(t_vm *vm)
{
	int		i;
	int		j;

	i = -1;
	while (++i < vm->nbr_pro && (j = -1))
		while (++j < vm->nbr_champs)
			if (vm->pro[i]->player == vm->champs[j].player)
				vm->pro[i]->color = vm->champs[j].color;
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
		vm->champs[i].color = i + 2;
		init_pair(i + 2, i + 1, -1);
		init_pair(i + 3 + vm->nbr_champs, COLOR_BLACK, i + 1);
	}
	init_pro_colors(vm);
}

int				init_ui(t_vm *vm)
{
	if (!vm->use_ui)
		return (1);
	initscr();
	curs_set(0);
	noecho();
	cbreak();
	init_colors(vm);
	refresh();
	if (!(vm->ui = new_ui()))
		return (0);
	ui_display_pause_title(*vm);
	refresh();
	ui_display_settings(*vm);
	ui_display_reg(vm);
	ui_display_pro(vm);
	ui_display_infos(*vm);
	ui_display_champs(*vm);
	return (1);
}
