/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_op.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 12:16:30 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 22:32:55 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char	add_label(t_pos data, int size, t_lab ***lab, int pos)
{
	int		i;
	char	*name;

	name = data.file[data.i][data.j];
	i = -1;
	while (lab[0][++i])
		;
	if (!(lab[0] = realloc(*lab, (i + 2) * sizeof(t_lab *))))
		return (1);
	if (!(lab[0][i] = malloc(sizeof(t_lab))))
		return (1);
	lab[0][i]->name = name;
	lab[0][i]->oct = size;
	if (name[0] == LABEL_CHAR)
		lab[0][i]->oct = IND_SIZE;
	lab[0][i]->i = data.i;
	lab[0][i]->i_for_bin = data.i + data.decal;
	lab[0][i]->j = data.j;
	lab[0][i]->pos = pos - lab[0][i]->oct + 1;
	lab[0][i + 1] = 0;
	return (0);
}

void	add_arg_bin(int ***bin, char *arg, int i, int oct)
{
	if (1 & i)
		add_bin_int(bin, ft_atoi(arg + 1), 1);
	else if (2 & i)
	{
		if (arg[1] == LABEL_CHAR)
			add_bin_int(bin, 0, oct);
		else
			add_bin_int(bin, ft_atoi(arg + 1), oct);
	}
	else
		add_bin_int(bin, ft_atoi(arg), IND_SIZE);
}

char	handle_op3(t_op op, int tot_line, int k, int ***bin)
{
	while (k++ < 4)
		tot_line = tot_line << 2;
	if (op.codage_octal)
		bin[0][bin_len(*bin) - 1][2] = tot_line;
	return (0);
}

int		handle_op2(t_pos d, t_op op, int ***bin, t_lab ***lab)
{
	int		i;
	int		tot_line;
	int		k;

	tot_line = 0;
	k = -1;
	add_bin_line(bin);
	add_bin_int(bin, op.opcode, 1);
	if (ft_tablen(&d.file[d.i][d.j + 1]) != op.nbr_arg)
		return (ft_error(ERROR_OP_LEN, op.nbr_arg, d.file[d.i][d.j]));
	if (op.codage_octal)
		add_bin_int(bin, 0, 1);
	while (++k < op.nbr_arg && (++d.j > -1))
	{
		if (!(i = op_type(d.file[d.i][d.j]) & op.arg[k]))
			return (ft_error(ERROR_OP_TYPE, PARAM));
		add_arg_bin(bin, d.file[d.i][d.j], i, op.dir_size);
		if (d.file[d.i][d.j][1] == LABEL_CHAR ||
		d.file[d.i][d.j][0] == LABEL_CHAR)
			if (add_label(d, op.dir_size, lab, bin[0][d.i +
			d.decal][0]))
				return (ft_error(ERROR_MALL));
		tot_line = (tot_line << 2) | param_bin(i);
	}
	return (handle_op3(op, tot_line, k, bin));
}

int		handle_op(t_pos data, t_op *op_tab, int ***bin, t_lab ***lab)
{
	int		i;

	i = -1;
	while (++i <= 15)
		if (!ft_strcmp(op_tab[i].name, data.file[data.i][data.j]))
			return (handle_op2(data, op_tab[i], bin, lab));
	return (ft_error(ER_OP, data.file[data.i][data.j]));
}
