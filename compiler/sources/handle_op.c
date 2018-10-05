/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_op.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 12:16:30 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 15:46:57 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char	add_label(char *name, int size, t_lab ***lab, int *pos)
{
	int		i;

	i = -1;
	while (lab[0][++i])
		;
	if (!(lab[0] = realloc(*lab, (i + 2) * sizeof(t_lab *))))
		return (-1);
	if (!(lab[0][i] = malloc(sizeof(t_lab))))
		return (0);
	lab[0][i]->name = name;
	lab[0][i]->oct = size;
	lab[0][i]->pos = pos;
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
		add_bin_int(bin, ft_atoi(arg), IND_SIZE / 2);
}

int		*good_bin(int ***bin, int oct)
{
	int		i;

	i = 0;
	while (bin[0][i])
		i++;
	i--;
	return (&bin[0][i][bin[0][i][0] - oct]);
}

int		handle_op2(char **file, t_op op, int ***bin, t_lab ***lab)
{
	int     i;
	int		j;
	int		tot_line;

	tot_line = 0;
	j = -1;
	add_bin_line(bin);
	add_bin_int(bin, op.opcode, 1);
	if (ft_tablen(file) != op.nbr_arg)
	{
		printf("len\n");
		return (6);
	}
	if (op.codage_octal)
		add_bin_int(bin, 0, 1);
	while (++j < op.nbr_arg)
	{
		if (!(i = op_type(file[j]) & op.arg[j]))
		{
			printf("%d\n",op_type(file[j]));
			printf("mauvais type de %d eme argument\n", j + 1);
			return (6);
		}
		add_arg_bin(bin, file[j], i, op.dir_size);
		if (file[j][1] == LABEL_CHAR)
			if (add_label(&file[j][2], op.dir_size, lab,
			good_bin(bin, op.dir_size)))
				return (-1);
		tot_line = (tot_line << 2) | param_bin(i);
	}
	while (j++ < 4)
		tot_line = tot_line << 2;
	if (op.codage_octal)
		bin[0][bin_len(*bin) - 1][2] = tot_line;
	return (0);
}

int		handle_op(char **file, t_op *op_tab, int ***bin, t_lab ***lab)
{
	int		i;

	i = -1;
	while (++i <= 15)
		if (!ft_strcmp(op_tab[i].name, file[0]))
			return (handle_op2(file + 1, op_tab[i], bin, lab));
	return (1);
}
