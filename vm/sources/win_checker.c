/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   win_checker.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:20:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 14:49:03 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		champs_len(t_champ **champs)
{
	int		i;
	
	i = -1;
	while (champs[++i])
		;
	return (i);
}

int		have_winner(t_vm vm)
{
	int		i;
	int		j;
	int		active_champ;
	
	active_champ = 0;
	i = -1;
	while (vm.champs[++i])
	{
		j = -1;
		while (vm.pro[++j])
			if (vm.pro[j]->player == vm.champs[i]->player && vm.pro[j]->active)
			{
				active_champ++;
				break ;
			}
	}
	if (champs_len(vm.champs) == 1 && active_champ == 0)
		return (1);
	else if (champs_len(vm.champs) > 1 && active_champ == 1)
		return (1);
	return (0);
}
