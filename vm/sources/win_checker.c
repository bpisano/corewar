/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   win_checker.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 18:03:29 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:03:27 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int			have_winner(t_vm vm)
{
	int		i;
	int		active_champ;
	
	i = -1;
	active_champ = 0;
	while (vm.champs[++i])
		if (vm.champs[i]->cur_live > 0)
			active_champ++;
	if (vm.nbr_champs == 1 && active_champ == 0)
		return (1);
	else if (vm.nbr_champs > 1 && active_champ <= 1)
		return (1);
	return (0);
}

t_champ		*winner(t_vm vm)
{
	int		i;
	
	i = -1;
	while (vm.champs[++i])
		if (vm.champs[i]->cur_live > 0)
			return (vm.champs[i]);
	return (NULL);
}

int			have_active_pro(t_vm vm)
{
	int		i;
	
	i = -1;
	while (vm.pro[++i])
		if (vm.pro[i]->active)
			return (1);
	return (0);
}
