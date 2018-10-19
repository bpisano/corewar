/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:09:18 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 18:38:52 by bpisano     ###    #+. /#+    ###.fr     */
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

int		main(int argc, char **argv)
{
	int     i;
	t_vm	vm;
	i = 0;
	if (argc == 1)
		return (error(0));
	if (argc > MAX_PLAYERS + 1)
		return (error(1));
	while (argv[++i])
		if (!(verif_champion(argv[i])))
			return (error(2));
	return (0);	
}
