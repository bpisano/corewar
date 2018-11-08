/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   initialisation.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 11:48:00 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 14:40:58 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

t_op	*initialisation(t_lab ***lab, t_pos *data, char **file_lines)
{
	if (!(*lab = malloc(sizeof(t_lab *))))
		return (0);
	**lab = NULL;
	data->decal = 0;
	data->i = -1;
	if (!(data->file = new_cmd_lines()))
		return (0);
	while (file_lines[++data->i])
	{
		if (!add_cmd_line(&(data->file), file_lines[data->i]))
			return (0);
	}
	data->i = -1;
	return (struct_tab());
}
