/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_text.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 17:16:20 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 16:59:51 by anamsell    ###    #+. /#+    ###.fr     */
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
	op_tab[8] = (t_op){"zjmp", 1, {T_DIR, 0, 0}, 9, 0, 2};
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

int		handle_label(t_pos data, int **bin, t_op *op_tab, t_lab **lab)
{
	t_label	**label;
	int		k;
	int		pos;

	data.i = -1;
	pos = 0;
	if (!(label = ft_memalloc(sizeof(t_label *))))
		return (-1);
	while (file[++data.i])
	{
		if (!is_op(file[data.i][0], op_tab))
			if (!(add_lab_list(file[data.i][0], pos, bin, &label)))
				return (-1);
		pos += bin[data.i][0];
	}
	data.i = -1;
	//free_label(label);
	return (0);
}

int		core_text(int ***bin, char **file_lines)
{
	t_pos	data;
	t_op	*op_tab;
	t_lab	**lab;

	if (!(lab = malloc(sizeof(t_lab *))))
		return (-1);
	*lab = NULL;
	op_tab = struct_tab();
	data.i = -1;
	if (!(data.file = new_cmd_lines()))
		return (-1);
	while (file_lines[++data.i])
	{
		if (!add_cmd_line(&(data.file), file_lines[data.i]))
			return (-1);
	}
	data.i = -1;
	while (data.file[++data.i] && !(data.j = 0))
	{
		printf("LIGNE\n");
		if (is_op(data.file[data.i][0], op_tab))
		{
			printf("op\n");
			if (handle_op(data, op_tab, bin, &lab))
				return (-1);
		}
		else if (!is_label(data.file[data.i][0]))
		{
//			printf("somestrchr\n");
			return (1);
		}
		else if ((is_op(data.file[data.i][1], op_tab)))
		{
			data.j += 1;
			printf("op 2\n");
			if (handle_op(data, op_tab, bin, &lab))
				return (-1);
		}
		else if (data.file[data.i][1])
			return (4);
	}
	data.i = 0;
	data.i  = handle_label(data, *bin, op_tab, lab);
	free(op_tab);
	free_cmd(&(data.file));
	return (data.i);
}
