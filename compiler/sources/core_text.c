/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_text.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 17:16:20 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 19:30:05 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char	is_op(char *str, t_op *op_tab)
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
		return (ft_error(ERROR_MALL));
	while (data.file[++data.i])
	{
		if (!is_op(data.file[data.i][0], op_tab))
			if (!(add_lab_list(data.file[data.i][0], pos, bin, &label)))
				return (free_l(label, ft_error(ERROR_MALL)));
		if (!data.file[data.i][1])
			data.j--;
		else
			pos += bin[data.i + data.j][0];
	}
	data.i = -1;
	while (lab[++data.i])
		if (fill_bin_lab(label, lab[data.i], bin))
			return (free_l(label, 10));
	return (free_l(label, 0));
}

char	*f(t_comp c, int i)
{
	return (c.data.file[c.data.i][i]);
}

int		core_text(int ***bin, char **file_lines)
{
	t_comp	c;

	if (!(c.op_tab = initialisation(&c.lab, &c.data, file_lines)))
		return (ft_error(ERROR_MALL));
	while (c.data.file[++c.data.i] && !(c.data.j = 0))
		if (is_op(c.data.file[c.data.i][0], c.op_tab))
		{
			if (handle_op(c.data, c.op_tab, bin, &c.lab))
				return (free_s(c.data, c.op_tab, c.lab, 10));
		}
		else if (!is_label(c.data.file[c.data.i][0]))
			return (free_s(c.data, c.op_tab, c.lab, ft_error(ER_LA, f(c, 0))));
		else if (!c.data.file[c.data.i][1])
			c.data.decal -= 1;
		else if (is_op(c.data.file[c.data.i][1], c.op_tab))
		{
			c.data.j += 1;
			if (handle_op(c.data, c.op_tab, bin, &c.lab))
				return (free_s(c.data, c.op_tab, c.lab, 10));
		}
		else
			return (free_s(c.data, c.op_tab, c.lab, ft_error(ER_OP, f(c, 1))));
	c.data.i = handle_label(c.data, *bin, c.op_tab, c.lab);
	free_s(c.data, c.op_tab, c.lab, 0);
	return (c.data.i);
}
