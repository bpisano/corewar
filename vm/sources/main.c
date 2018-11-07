/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:09:18 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 18:37:24 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		init(char **argv, t_vm *vm)
{
	int		i;

	i = 0;
	vm->dump = -1;
	vm->champs[0] = 0;
	if (!(vm->nbr_champs = count_champs(argv)))
		return (ft_printf(ERROR_NUMB));
	while (argv[++i])
		if (!argv[i][0])
			continue;
		else if (!ft_strcmp(argv[i], "-n") || !ft_strcmp(argv[i], "-number"))
		{
			if (check_flag_n(argv, &i, vm))
				return (1);
		}
		else if (!ft_strcmp(argv[i], "-d") || !ft_strcmp(argv[i], "-dump"))
		{
			if (check_flag_d(argv, &i, &vm->dump))
				return (1);
		}
		else if (!ft_strchr(argv[i], '.'))
			return (invalid_param(argv[i]));
		else if (valid_champ(argv[i], vm, ""))
			return (ft_printf(ERROR_CHMP, argv[i]));
	return (0);
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	(void)argc;
	if (init(argv, &vm))
		return (0/*free_vm_champs(vm)*/);
}
