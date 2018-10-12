/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_text.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 17:16:20 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 14:42:13 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

int		is_op(char *str, t_op *op_tab)
{
	int		i;

	i = -1;
	while (++i < 16)
		if (!ft_strcmp(op_tab[i].name, str))
			return (1);
	return (0);
}

int		handle_label(t_pos data, int **bin, t_op *op_tab, t_lab **lab)
{
	t_label	**label;
	int		k;
	int		pos;

	data.i = -1;
	pos = 0;
	data.j = 0;
	if (!(label = ft_memalloc(sizeof(t_label *))))
		return (-1);
	while (data.file[++data.i])
	{
		if (!is_op(data.file[data.i][0], op_tab))
			if (!(add_lab_list(data.file[data.i][0], pos, bin, &label)))
				return (-1);
		if (!data.file[data.i][1])
			data.j--;
		else
			pos += bin[data.i + data.j][0];
	}
	data.i = -1;
	while (lab[++data.i])
		if ((data.j = fill_bin_lab(label, lab[data.i], bin)))
			return (data.j);
	return (0);
}

int		core_text(int ***bin, char **file_lines)
{
	t_pos	data;
	t_op	*op_tab;
	t_lab	**lab;

	if (!(op_tab = initialisation(&lab, &data, file_lines)))
		return (-1);
	while (data.file[++data.i] && !(data.j = 0))
		if (is_op(data.file[data.i][0], op_tab))
		{
			if (handle_op(data, op_tab, bin, &lab))
				return (1);
		}
		else if (!is_label(data.file[data.i][0]))
			return (-1);
		else if (!data.file[data.i][1])
			data.decal -= 1;
		else if (is_op(data.file[data.i][1], op_tab))
		{
			data.j += 1;
			if (handle_op(data, op_tab, bin, &lab))
				return (-1);
		}
		else
			return (-1);
	data.i = handle_label(data, *bin, op_tab, lab);
	free(op_tab);
	free_cmd(&(data.file));
	return (data.i);
}
