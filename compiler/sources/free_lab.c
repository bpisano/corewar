/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_lab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:22:55 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:27:43 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

void	free_lab1(t_label *lab)
{
	if (lab->name)
		free_lab1(lab->next);
	free(lab);
}

void	free_lab(t_label *lab)
{
	if (lab->name)
		free_lab1(lab->next);
}
