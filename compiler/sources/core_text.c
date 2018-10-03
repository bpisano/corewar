/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_text.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 17:16:20 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:13:32 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

t_op	*struct_tab2(t_op *op_tab)
{
	op_tab[11] = (t_op){"fork", 1, {T_DIR, 0, 0}, 12, 0, 2};
	op_tab[12] = (t_op){"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 1, 4};
	op_tab[13] = (t_op){"lldi", 3,
	{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 1, 2};
	op_tab[14] = (t_op){"lfork", 1, {T_DIR, 0, 0}, 15, 0, 2};
	op_tab[15] = (t_op){"aff", 1, {T_REG, 0, 0}, 16, 1, 0};
	return (op_tab);
}

t_op	*struct_tab(void)
{
	t_op	*op_tab;

	if (!(op_tab = malloc(16 * sizeof(t_op))))
		return (0);
	op_tab[0] = (t_op){"live", 1, {T_DIR, 0, 0}, 1, 0, 4};
	op_tab[1] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 1, 4};
	op_tab[2] = (t_op){"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 1, 0};
	op_tab[3] = (t_op){"add", 3, {T_REG, T_REG, T_REG}, 4, 1, 0};
	op_tab[4] = (t_op){"sub", 3, {T_REG, T_REG, T_REG}, 5, 1, 0};
	op_tab[5] = (t_op){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND |
	T_DIR, T_REG}, 6, 1, 4};
	op_tab[6] = (t_op){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND |
	T_DIR, T_REG}, 7, 1, 4};
	op_tab[7] = (t_op){"xor", 3,
	{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 1, 4};
	op_tab[8] = (t_op){"zjmp", 1, T_DIR, 9, 0, 2};
	op_tab[9] = (t_op){"ldi", 3,
	{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 1, 2};
	op_tab[10] = (t_op){"sti", 3,
	{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 1, 2};
	return (struct_tab2(op_tab));
}

int		is_op(char *str, t_op *op_tab)
{
	int		i;

	i = -1;
	while (++i < 16)
		if (!ft_strcmp(op_tab[i].name, str))
			return (1);
	return (0);
}

int		handle_label(char ***file, int **bin, t_op *op_tab)
{
	t_label	lab;
	int		i;
	int		j;
	int		pos;

	i = -1;
	pos = 0;
	lab.name= 0;
	while (file[++i])
	{
		if (!is_op(file[i][0], op_tab))
			if (!(add_lab_list(file[i][0], pos, bin, &lab)))
				return (-1);
		pos += bin[i + 1][0];
	}
	printf("Bon APRES list\n");
	i = 0;
	j = 0;
	pos = 0;
	while (bin[0][0] >= ++i && !(j = 0))
	{
		while (bin[i][0] >= ++j)
			if (bin[i][j] == LAB_NUMB)
				if (!fill_bin_lab(&(bin[i][j]), file[i - 1], lab, pos))
					return (-6);
		pos += bin[i][0];
	}
	return (0);
}

int		core_text(int ***bin, char **file_lines)
{
	int		i;
	char	***file;
	t_op	*op_tab;

	op_tab = struct_tab();
	i = -1;
	if (!(file = new_cmd_lines()))
		return (-1);
	while (file_lines[++i])
	{
		if (!add_cmd_line(&file, file_lines[i]))
			return (-1);
	}
	i = -1;
	while (file[++i])
	{
		printf("LIGNE\n");
		if (is_op(file[i][0], op_tab))
		{
			printf("op\n");
			if (handle_op(file[i], op_tab, bin))
				return (6);
		}
		else if (!is_label(file[i][0]))
		{
			printf("somestrchr\n");
			return (6);
		}
		else if ((is_op(file[i][1], op_tab)))
		{
			printf("op + 1\n");
			if (handle_op(file[i] + 1, op_tab, bin))
				return (6);
		}
		else if (file[i][1])
			return (6);
	}
	i  = handle_label(file, *bin, op_tab);
	free(op_tab);
	return (i);
}
