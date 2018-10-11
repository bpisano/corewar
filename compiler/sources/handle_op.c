/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_op.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 12:16:30 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 16:52:34 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char	add_label(t_pos data, int size, t_lab ***lab)
{
	int		i;
	char	*name;

	name = &data.file[data.i][data.j][2];
	i = -1;
	printf("			%s\n", name);
	while (lab[0][++i])
		;
	if (!(lab[0] = realloc(*lab, (i + 2) * sizeof(t_lab *))))
		return (-1);
	if (!(lab[0][i] = malloc(sizeof(t_lab))))
		return (0);
	lab[0][i]->name = name;
	lab[0][i]->oct = size;
	lab[0][i]->i = data.i;
	lab[0][i]->j = data.j;
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

/*int		*good_bin(int ***bin, int oct)
{
	int		i;

	i = 0;
	while (bin[0][i])
		i++;
	i--;
	return (&bin[0][i][bin[0][i][0] - oct + 1]);
}*/

int		handle_op2(t_pos data, t_op op, int ***bin, t_lab ***lab)
{
	int     i;
	int		tot_line;
	int		k;

	tot_line = 0;
	k = -1;
	add_bin_line(bin);
	add_bin_int(bin, op.opcode, 1);
	if (ft_tablen(&data.file[data.i][data.j + 1]) != op.nbr_arg)
	{
		printf("len\n");
		return (6);
	}
	if (op.codage_octal)
		add_bin_int(bin, 0, 1);
	while (++data.j < op.nbr_arg && (++k > -1))
	{
		if (!(i = op_type(data.file[data.i][data.j]) & op.arg[k]))
		{
			printf("%d\n",op_type(data.file[data.i][data.j]));
			printf("mauvais type de %d eme argument\n", data.j + 1);
			return (6);
		}
		add_arg_bin(bin, data.file[data.i][data.j], i, op.dir_size);
		printf("%d\n",data.j);
		if (data.file[data.i][data.j][1] == LABEL_CHAR)
			if (add_label(data, op.dir_size, lab))
				return (-1);
		tot_line = (tot_line << 2) | param_bin(i);
	}
	printf("\n");
	while (data.j++ < 4)
		tot_line = tot_line << 2;
	if (op.codage_octal)
		bin[0][bin_len(*bin) - 1][2] = tot_line;
	return (0);
}

int		handle_op(t_pos data, t_op *op_tab, int ***bin, t_lab ***lab)
{
	int		i;

	i = -1;
	while (++i <= 15)
		if (!ft_strcmp(op_tab[i].name, data.file[data.i][data.j]))
			return (handle_op2(data, op_tab[i], bin, lab));
	return (1);
}
