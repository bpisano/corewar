/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 16:43:59 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int				number_of_pro(t_vm vm)
{
	int		i;
	
	i = -1;
	while (vm.pro[++i])
		;
	return (1);
}

static int		add_pro(t_vm *vm, t_pro *pro)
{
	int		pro_number;
	
	pro_number = number_of_pro(*vm);
	if (!(realloc(vm->pro, sizeof(t_pro *) * (pro_number + 2))))
		return (0);
	vm->pro[pro_number] = pro;
	vm->pro[pro_number + 1] = 0;
	return (1);
}

int				init_process(t_vm *vm)
{
	int		i;
	
	if (!(vm->pro = (t_pro **)ft_memalloc(sizeof(t_pro *))))
		return (0);
	i = -1;
	while (vm->champs[++i])
		if (!add_pro(vm, new_pro_from_champ(*(vm->champs[i]), *vm)))
		{
			free_pro(vm);
			return (0);
		}
	return (1);
}
