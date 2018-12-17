/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_aff.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 22:52:37 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 23:16:38 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_aff(t_pro *pro, t_vm *vm)
{
	int				p[3];
	unsigned		c;

	params(*pro, *vm, p);
	c = pro->reg[p[0]] % 256;
	if (vm->aff)
		ft_printf("aff : %c\n", c);
	goto_next_operation(pro, vm);
}
