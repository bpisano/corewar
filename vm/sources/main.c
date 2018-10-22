/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:09:18 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/21 23:04:48 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		error(int i)
{
	if (i == 0)
	{
		ft_printf("ERROR NO CHAMPS\n");
		return (0);
	}
	if (i == 1)
	{
		ft_printf("ERROR T00 MANY CHAMPS\n");
		return (0);
	}
	return (0);
}

int		init(char **argv, t_vm *vm)
{
	int		i;

	i = 0;
	vm->dump = -1;
	vm->champs[0] = 0;
	if (!(vm->nbr_champs = count_champs(argv)))
		return (ft_printf(ERROR_NUMB));
	while (argv[++i])
	{
		if (!argv[i][0])
			continue;
		if (!ft_strcmp(argv[i], "-n") || !ft_strcmp(argv[i], "-number"))
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
			return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	(void)argc;
	if (init(argv, &vm))
		return (0/*free_vm_champs(vm)*/);
}
