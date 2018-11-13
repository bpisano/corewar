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

void	init_var(t_vm *vm)
{
	int		i;

	i = -1;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->max_checks = MAX_CHECKS;
	vm->dump = -1;
	vm->champs[0] = 0;
	vm->op_tab = struct_tab();
	vm->ui = 0;
	while (++i < MEM_SIZE)
		vm->reg[i] = 0;
}

int		init(char **argv, t_vm *vm)
{
	int		i;

	i = 0;
	if (!(vm->nbr_champs = count_champs(argv)) || vm->nbr_champs > MAX_PLAYERS)
		return (ft_printf(ERROR_NUMB, MAX_PLAYERS));
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
		else if (invalid_champ(argv[i], vm, ""))
			return (ft_printf(ERROR_CHMP, i, argv[i]));
	return (0);
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	(void)argc;
	init_var(&vm);
	print_vm(vm);
	if (init(argv, &vm))
		return (0);
	if (!exec_vm(&vm))
		return (0);
	return (0);
}
