/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 22:58:07 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 22:58:13 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_sub(t_pro *pro, t_vm *vm)
{
	int		p[3];

	params(*pro, *vm, p);
	pro->reg[p[2]] = pro->reg[p[0]] - pro->reg[p[1]];
	pro->carry = 0;
	if (!pro->reg[p[2]])
		pro->carry = 1;
	goto_next_operation(pro, vm);
}
