/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   param_bin.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 12:37:51 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 09:54:16 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char		param_bin(int op_code)
{
	if (op_code == T_REG)
		return (REG_CODE);
	else if (op_code == T_DIR || op_code == T_LAB)
		return (DIR_CODE);
	else if (op_code == T_IND)
		return (IND_CODE);
	return (0);
}
