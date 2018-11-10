/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_text.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 17:16:20 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 10:34:06 by anamsell    ###    #+. /#+    ###.fr     */
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
		return (4);
	while (data.file[++data.i])
	{
		if (!is_op(data.file[data.i][0], op_tab))
			if (!(add_lab_list(data.file[data.i][0], pos, bin, &label)))
				return (free_struct_label(label, 4));
		if (!data.file[data.i][1])
			data.j--;
		else
			pos += bin[data.i + data.j][0];
	}
	data.i = -1;
	while (lab[++data.i])
		if ((data.j = fill_bin_lab(label, lab[data.i], bin)))
			return (free_struct_label(label, data.j));
	return (free_struct_label(label, 0));
}

int		core_text(int ***bin, char **file_lines)
{
	t_comp	comp;

	if (!(comp.op_tab = initialisation(&comp.lab, &comp.data, file_lines)))
		return (ft_printf(ERROR_MALL));
	while (comp.data.file[++comp.data.i] && !(comp.data.j = 0))
		if (is_op(comp.data.file[comp.data.i][0], comp.op_tab))
		{
			if (handle_op(comp.data, comp.op_tab, bin, &comp.lab))
				return (free_struct(comp.data, comp.op_tab, comp.lab, 10));
		}
		else if (!is_label(comp.data.file[comp.data.i][0]))
			return (free_struct(comp.data, comp.op_tab, comp.lab, 5));
		else if (!comp.data.file[comp.data.i][1])
			comp.data.decal -= 1;
		else if (is_op(comp.data.file[comp.data.i][1], comp.op_tab))
		{
			comp.data.j += 1;
			if (handle_op(comp.data, comp.op_tab, bin, &comp.lab))
				return (free_struct(comp.data, comp.op_tab, comp.lab, 10));
		}
		else
			return (free_struct(comp.data, comp.op_tab, comp.lab, 5));
	comp.data.i = handle_label(comp.data, *bin, comp.op_tab, comp.lab);
	free_struct(comp.data, comp.op_tab, comp.lab, 5);
	return (comp.data.i);
}
