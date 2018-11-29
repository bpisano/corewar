/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:09:18 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 13:54:05 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		init_var(t_vm *vm, char **argv)
{
	int		i;

	i = -1;
	vm->nbr_champs = count_champs(argv);
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->max_checks = MAX_CHECKS;
	vm->dump = -1;
	vm->champs[0] = 0;
	if (!(vm->op_tab = struct_tab()))
		return (0);
	vm->pro = 0;
	vm->use_ui = 0;
	vm->cycles_total = 0;
	vm->nbr_pro = vm->nbr_champs;
	while (++i < MEM_SIZE)
		vm->reg[i] = 0;
	i = -1;
	while (++i < MAX_PLAYERS)
		vm->champs[i] = 0;
	return (1);
}

int		init(char **argv, t_vm *vm)
{
	int		i;

	i = 0;
	if (!vm->nbr_champs || vm->nbr_champs > MAX_PLAYERS)
		return (ft_printf(ERROR_NUMB, MAX_PLAYERS));
	while (argv[++i])
	{
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
		else if (!ft_strcmp(argv[i], "-i"))
			vm->use_ui = 1;
		else if (!ft_strchr(argv[i], '.'))
			return (invalid_param(argv[i]));
		else if (invalid_champ(argv[i], vm, 0))
			return (ft_printf(ERROR_CHMP, i, argv[i]));
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	(void)argc;
	if (!init_var(&vm, argv))
		return (0);
	if (init(argv, &vm))
	{
		free_vm(&vm);
		return (0);
	}
	if (!exec_vm(&vm))
		return (0);
	return (0);
}
