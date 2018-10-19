/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 15:37:11 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 14:27:20 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"

typedef struct		s_pro
{
	int				pc;
	int				live;
	int				carry;
	int				reg[REG_NUMBER];
}					t_pro;

typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	char			player;
	unsigned int	last_live;
	unsigned int	cur_live;
}					t_champ;

typedef struct		s_vm
{
	char			reg[MEM_SIZE];
	int				cycle_to_die;
	int				max_checks;
	
	int				dump;
	int				ui;
	
	t_champ			*champs[MAX_PLAYERS + 1];
	t_pro			**pro;
}					t_vm;

/*
 ** VM
*/

int					exec_vm(t_vm *vm);
int					init_process(t_vm *vm);

#endif
