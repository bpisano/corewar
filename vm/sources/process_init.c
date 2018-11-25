/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 16:32:44 by anamsell    ###    #+. /#+    ###.fr     */
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
	return (i);
}

int				init_process(t_vm *vm)
{
	int		i;
	t_pro	*new;

	if (!(vm->pro = malloc(sizeof(t_pro *) * vm->nbr_champs)))
		return (0);
	i = -1;
	while (vm->champs[++i])
	{
		if (!(new = new_pro_from_champ(*(vm->champs[i]), *vm, i)))
		{
			free_pro(vm);
			return (0);
		}
		vm->pro[i] = new;
	}
	return (1);
}
