/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   corewar.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 17:36:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 17:36:46 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

typedef	struct		s_op
{
	char			*name;
	int				nbr_arg;
	char			arg[3];
	int				opcode;
	char			codage_octal;
	int				dir_size;
	int				cycles;
	int				carry;
}					t_op;

t_op				*struct_tab(void);

#endif
