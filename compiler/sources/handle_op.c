/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_op.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 12:16:30 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 19:17:05 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

void	add_arg_bin(int ***bin, char *arg, int i, int oct)
{
	if (1 & i)
		add_bin_int(bin, ft_atoi(arg + 1), 1);
	else if (2 & i)
	{
		if (arg[1] == LABEL_CHAR)
			add_bin_int(bin, LAB_NUMB, REG_SIZE / 2);
		else
			add_bin_int(bin, ft_atoi(arg + 1), oct);
	}
	else
		add_bin_int(bin, ft_atoi(arg), IND_SIZE / 2);
}

int		handle_op2(char **file, t_op op, int ***bin)
{
	int     i;
	int		j;
	int		tot_line;

	tot_line = 0;
	j = -1;
	add_bin_line(bin);
	add_bin_int(bin, op.opcode, 1);
	file++;
	if (ft_strlen(*file) != op.nbr_arg)
		return (-6);
	if (op.codage_octale)
		add_bin_int(bin, 0, 1);
	while (++j < op.nbr_arg)
	{
		if (!(i = op_type(file[j]) & op.arg[j]))
			return (6);
		add_arg_bin(bin, i, file[j], op.dir_size);
		tot_line = (tot_line << 2) | param_bin(i);
	}
	while (j++ < 4)
		tot_line = tot_line << 2;
	if (op.codage_octale)
		bin[0][bin_len(bin) - 1][1] = tot_line;
}

int		handle_op(char **file, t_op *op_tab, int ***bin)
{
	int		i;

	i = -1;
	while (++i <= 15)
		if (!ft_strcmp(op_tab[i].name, file[0]))
			return (handle_op2(file + 1), op_tab[i],bin);
	return (0);
}