/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fnc.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 23:29:32 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 15:09:18 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		check_taken(unsigned int i, t_vm *vm)
{
	int		j;

	j = -1;
	while (++j < vm->last_champ)
		if (vm->champs[j].player == i)
			return (1);
	return (0);
}

int		convert_hexa_int(char a, char b)
{
	int		i;

	if (a <= '9')
		i = (a - '0') * 16;
	else
		i = (a - 'A' + 10) * 16;
	if (b <= '9')
		i += b - '0';
	else
		i += b - 'A' + 10;
	return (i);
}

int		handle_number(t_vm *vm, char *number, int j)
{
	unsigned int	i;

	if (number)
	{
		i = -(unsigned int)ft_atoi(number);
		if (check_taken(i, vm))
			return (1);
		vm->champs[j].player = i;
		return (0);
	}
	i = 0xffffffff;
	vm->champs[j].player = 0;
	while (i != 0)
	{
		if (!check_taken(i, vm))
		{
			vm->champs[j].player = i;
			return (0);
		}
		i--;
	}
	return (1);
}
