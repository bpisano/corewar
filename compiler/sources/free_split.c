/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_split.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 11:14:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 17:23:47 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

void			free_split(char **split)
{
	int		i;

	if (!split)
		return ;
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int				free_s(t_pos data, t_op *op, t_lab **lab, int i)
{
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

int				free_l(t_label **label, int i)
{
	int		j;

	j = -1;
	while (label[++j])
		free(label[j]);
	free(label);
	return (i);
}
