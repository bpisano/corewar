/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op_type.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 12:37:51 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 16:21:01 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

static int		is_reg(char *op)
{	
	if (op[0] != 'r' || ft_strlen(op) < 2)
		return (0);
	if (!ft_str_is_numeric(op + 1) || op[1] == '0')
		return (0);
	return (ft_atoi(op + 1) > 0 && ft_atoi(op + 1) <= REG_NUMBER);
}

static int		is_lab(char *op)
{
	if (ft_strlen(op) < 3)
		return (0);
	if (op[0] != DIRECT_CHAR || op[1] != LABEL_CHAR)
		return (0);
	if (!ft_somestrchr(op + 2, LABEL_CHARS))
		return (0);
	return (1);
}

static int		is_dir(char *op)
{
	if (ft_strlen(op) < 2)
		return (0);
	return (op[0] == DIRECT_CHAR && ft_str_is_numeric(op + 1) && op[1] != 0);
}

int				op_type(char *op)
{
	if (is_reg(op))
		return (T_REG);
	else if (is_dir(op))
		return (T_DIR);
	else if (ft_str_is_numeric(op))
		return (T_IND);
	else if (is_lab(op))
		return (T_DIR);
	return (0);
}

int				param_bin(int op_code)
{
	if (op_code == T_REG)
		return (REG_CODE);
	else if (op_code == T_DIR || op_code == T_LAB)
		return (DIR_CODE);
	else if (op_code == T_IND)
		return (IND_CODE);
	return (0);
}
