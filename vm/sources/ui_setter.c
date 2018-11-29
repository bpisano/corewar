/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_setter.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 14:48:54 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	need_pro_display(t_vm *vm)
{
	if (!vm->use_ui)
		return ;
	vm->ui->need_pro_disp = 1;
}

void	need_champ_display(t_vm *vm)
{
	if (!vm->use_ui)
		return ;
	vm->ui->need_cha_disp = 1;
}
