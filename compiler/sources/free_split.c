/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_split.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 11:14:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 12:34:38 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "compiler.h"

int				free_struct(t_pos data, t_op *op, t_lab **lab, int i)
{
	printf("ok\n");
	free(op);
	data.i = -1;
	while (data.file[++data.i] && (data.j = -1))
	{
		while (data.file[data.i][++data.j])
			free(data.file[data.i][data.j]);
		free(data.file[data.i]);
	}
	free(data.file);
	data.i = -1;
	while (lab[++data.i])
		free(lab[data.i]);
	free(lab);
	return (i);
}
