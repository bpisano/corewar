/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   usage.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <bpisano@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 13:41:15 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 14:21:09 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

void	vm_usage(void)
{
	ft_printf("usage : ./corewar [champ.cor ...]\n");
	ft_printf("\t[-i] User interface\n");
	ft_printf("\t[-n num] Set custom champion's number\n");
	ft_printf("\t[-d num] Dump vm at custom cycle\n");
	ft_printf("\t[-a] Display aff function result on standard output\n");
	exit(0);
}
