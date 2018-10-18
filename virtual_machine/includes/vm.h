/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 15:37:11 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 17:47:40 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VM_H
#define VM_H

typedef struct		s_proc
{
	char			live;
	int             pc;
	int             carry;
	int				reg[REG_NUMBER];
}                   t_proc;

typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	char            player;
	unsigned int    last_live;
	unsigned int    cur_live;
	t_proc          **process;
}                   t_champ;

typedef struct      s_vm
{
	char            reg[MEM_SIZE];
	int             cycle_to_die;
	int				max_checks;
	t_champ			*champs[MAX_PLAYERS + 1];
}                   t_vm;

int					verif_champion(char *name);

#endif
