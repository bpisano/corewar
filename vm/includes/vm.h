/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 15:37:11 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 22:14:28 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "corewar.h"
# include "op.h"

# define ERROR_N1	"Bad argument : %d, need a number after -n flag\n"
# define ERROR_N2	"Bad argument : %d, need a a valid champion after -n numb\n"
# define ERROR_D1	"Bad argument : %d, need a number after -dump flag\n"
# define ERROR_D2	"Flag -dump use several time\n"
# define ERROR_C	"Bad argument : %d, \"%s\" is not a valid champ\n"
# define ERROR_OPEN	"Open error, \"%s\" cannot be opened or does not exist\n"
# define ERROR_NUMB	"Error no champs\n"
# define ERROR_ASM	"Error \"%s\" is a .s, do \"./asm %s\" before\n"
# define ERROR_F1	"Error nothing afer -, use -n or -dump\n"
# define ERROR_F2	"Error \"%s\" is not handle, bpisano is the one to blame\n"
# define ERROR_FILE	"Error \"%s\" is not a file\n"
# define ERROR_COR	"Error \"%s\" is not a .cor\n"
# define ERROR_MALL	"Error of memory allocation\n"
# define ERROR_0	"Error the first octet must be 0x00\n"
# define ERROR_MGC	"Error the COREWAR_EXEC_MAGIC is not correct\n"
# define ERROR_CHMP	"Error in the parameter number %d: \"%s\"\n"
# define ERROR_NAME	"Error in the champs number %d, the name is incorrect\n"
# define ERROR_READ	"Error, invalid file\n"
# define ERROR_CONT	"Error, content is too long\n"
# define ERROR_SIZE	"Error, bad content size %d\n"
# define ERROR_COM	"Error, comment is too long\n"
# define ERROR_NBR	"Error, the player number (%d) is already taken\n"

typedef struct		s_pro
{
	int				id;
	int				player;
	int				pc;
	int				cycles;

	int				live;
	int				active;
	int				carry;

	int				reg[REG_NUMBER];
}					t_pro;

typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned char	player;

	unsigned int	last_live;
	unsigned int	cur_live;
	unsigned int	pc;
}					t_champ;

typedef struct		s_vm
{
	char			reg[MEM_SIZE];
	int				cycle_to_die;
	int				max_checks;
	int				nbr_champs;

	int				dump;
	int				ui;

	t_champ			*champs[MAX_PLAYERS + 1];
	t_pro			**pro;
}					t_vm;

/*
 ** VM
*/

int					check_flag_n(char **argv, int *i, t_vm *vm);
int					check_flag_d(char **argv, int *i, int *dump);
int					invalid_champ(char *name, t_vm *vm, char *number);
int					count_champs(char **argv);
int					invalid_param(char *argv);
int					convert_hexa_int(char a, char b);
int					handle_number(t_vm *vm, char *number, int j);
int					free_chmp(t_vm *vm);

int					exec_vm(t_vm *vm);

/*
 ** Processes
*/

int					init_process(t_vm *vm);
int					number_of_pro(t_vm vm);
t_pro				*new_pro_from_champ(t_champ champ, t_vm vm);
t_pro				*new_pro_from_pro(t_pro pro, int dir, t_vm vm);
void				free_pro(t_vm *vm);
void				increment_pc(int increment, t_pro *pro);

int					have_winner(t_vm vm);
t_champ				*winner(t_vm vm);
int					have_active_pro(t_vm vm);

void				exec_pro(t_pro *pro, t_vm *vm);

/*
 ** REG
*/

int					num_at_reg(t_vm vm, size_t reg, size_t size);
void				set_num_at_reg(t_vm *vm, int n, size_t reg);

/*
 ** OPERATIONS
*/

void				live(t_pro *pro, t_vm *vm);

#endif
