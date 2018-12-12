/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operations.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:01:21 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 16:01:21 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

t_op	*struct_tab2(t_op *op_tab)
{
	op_tab[11] = (t_op){"fork", 1, {T_DIR, 0, 0}, 12, 0, 2, 800, 0};
	op_tab[12] = (t_op){"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 1, 4, 10, 1};
	op_tab[13] = (t_op){"lldi", 3,
	{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 1, 2, 50, 1};
	op_tab[14] = (t_op){"lfork", 1, {T_DIR, 0, 0}, 15, 0, 2, 1000, 0};
	op_tab[15] = (t_op){"aff", 1, {T_REG, 0, 0}, 16, 1, 4, 2, 0};
	return (op_tab);
}

t_op	*struct_tab(void)
{
	t_op	*op_tab;

	if (!(op_tab = malloc(16 * sizeof(t_op))))
		return (0);
	op_tab[0] = (t_op){"live", 1, {T_DIR, 0, 0}, 1, 0, 4, 10, 0};
	op_tab[1] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 1, 4, 5, 1};
	op_tab[2] = (t_op){"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 1, 4, 5, 0};
	op_tab[3] = (t_op){"add", 3, {T_REG, T_REG, T_REG}, 4, 1, 4, 10, 1};
	op_tab[4] = (t_op){"sub", 3, {T_REG, T_REG, T_REG}, 5, 1, 4, 10, 1};
	op_tab[5] = (t_op){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND |
	T_DIR, T_REG}, 6, 1, 4, 6, 1};
	op_tab[6] = (t_op){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND |
	T_DIR, T_REG}, 7, 1, 4, 6, 1};
	op_tab[7] = (t_op){"xor", 3,
	{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 1, 4, 6, 1};
	op_tab[8] = (t_op){"zjmp", 1, {T_DIR, 0, 0}, 9, 0, 2, 20, 0};
	op_tab[9] = (t_op){"ldi", 3,
	{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 1, 2, 25, 0};
	op_tab[10] = (t_op){"sti", 3,
	{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 1, 2, 25, 0};
	return (struct_tab2(op_tab));
}
