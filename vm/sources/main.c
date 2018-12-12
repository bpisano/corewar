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
	ft_bzero(vm->champs, sizeof(vm->champs));
	if (!(vm->op_tab = struct_tab()))
		return (0);
	vm->last_champ = 0;
	vm->pro = 0;
	vm->use_ui = 0;
	vm->cycles_total = 0;
	vm->total_live = 0;
	vm->nbr_pro = vm->nbr_champs;
	vm->nbr_pro_alive = vm->nbr_champs;
	while (++i < MEM_SIZE)
		vm->reg[i] = 0;
	i = -1;
	return (1);
}

int		check_flag(char *argv, int *i, t_vm *vm)
{
	if (!argv[0])
		return (-1);
	else if (!ft_strcmp(argv, "-n") || !ft_strcmp(argv, "-number"))
	{
		if (check_flag_n(&argv, i, vm))
			return (1);
	}
	else if (!ft_strcmp(argv, "-d") || !ft_strcmp(argv, "-dump"))
	{
		if (check_flag_d(&argv, i, &vm->dump))
			return (1);
	}
	else if (!ft_strcmp(argv, "-i"))
		vm->use_ui = 1;
	else if (!ft_strchr(argv, '.'))
		return (invalid_param(argv));
	else if (invalid_champ(argv, vm, 0))
		return (ft_error(ERROR_CHMP, *i, argv));
	return (0);
}

int		init(char **argv, t_vm *vm)
{
	int		i;
	int		flag_ret;

	i = 0;
	if (!vm->nbr_champs || vm->nbr_champs > MAX_PLAYERS)
		return (ft_error(ERROR_NUMB, MAX_PLAYERS));
	while (argv[++i])
	{
		flag_ret = check_flag(argv[i], &i, vm);
		if (flag_ret == -1)
			continue;
		else if (flag_ret == 1)
			return (1);
		else if (flag_ret != 0)
			return (flag_ret);
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
		free_vm(&vm, 0);
		return (0);
	}
	if (!exec_vm(&vm))
		return (0);
	return (0);
}
