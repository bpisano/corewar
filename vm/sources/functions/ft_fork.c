/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fork.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 22:54:21 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 22:54:27 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	ft_fork(t_pro *pro, t_vm *vm)
{
	short	addr;
	t_pro	*new;

	addr = num_at_reg(*vm, pro->pc + 1, 2);
	if (!(new = new_pro_from_pro(*pro, *vm)))
		return ;
	new->pc = ft_mod(pro->pc + (addr % IDX_MOD), MEM_SIZE);
	new->last_pc = new->pc;
	new->op_code = NEW_OP;
	need_pro_display(vm);
	if (!(vm->pro = realloc(vm->pro, sizeof(t_pro) * (vm->nbr_pro + 1))))
		return ;
	vm->pro[vm->nbr_pro] = new;
	vm->nbr_pro++;
	vm->nbr_pro_alive++;
	goto_next_operation(pro, vm);
}
