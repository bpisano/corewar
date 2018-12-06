/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 15:37:11 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 05:34:41 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "corewar.h"
# include "op.h"
# include <ncurses.h>

# define ERROR_N1	"Bad argument : %d, need a number after -n flag\n"
# define ERROR_N2	"Bad argument : %d, need a a valid champion after -n numb\n"
# define ERROR_D1	"Bad argument : %d, need a number after -dump flag\n"
# define ERROR_D2	"Flag -dump use several time\n"
# define ERROR_C	"Bad argument : %d, \"%s\" is not a valid champ\n"
# define ERROR_OPEN	"Open error, \"%s\" cannot be opened or does not exist\n"
# define ERROR_NUMB	"Error need a least 1 champ and no more then %d champs\n"
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

# define NEW_OP 256

typedef	struct		s_win
{
	WINDOW			*win;

	int				x;
	int				y;
	int				width;
	int				height;
}					t_win;

typedef struct		s_ui
{
	int				width;
	int				height;
	int				colors[MEM_SIZE];
	int				bold[MEM_SIZE];

	int				need_pro_disp;
	int				need_cha_disp;

	t_win			*reg_win;
	t_win			*info_win;
}					t_ui;

typedef struct		s_pro
{
	unsigned int	player;
	int				last_pc;
	int				pc;
	int				op_size;
	int				cycles;
	unsigned short	op_code;

	int				color;
	int				live;
	int				carry;

	unsigned int	reg[REG_NUMBER + 1];
}					t_pro;

typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	player;

	unsigned int	last_live;
	unsigned int	cur_live;
	unsigned int	live;
	unsigned int	pc;

	int				color;
	unsigned int	size;			
}					t_champ;

typedef struct		s_vm
{
	unsigned char	reg[MEM_SIZE];
	int				cycle_to_die;
	int				max_checks;
	int				nbr_champs;
	int				cycles_total;
	unsigned int	total_live;

	int				dump;
	int				use_ui;
	unsigned int	nbr_pro;
	unsigned int	nbr_pro_alive;

	t_champ			*champs[MAX_PLAYERS];
	t_pro			**pro;
	t_op			*op_tab;
	t_ui			*ui;
}					t_vm;

void				print_vm(t_vm vm);

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
void				free_vm(t_vm *vm, int ui);

/*
 ** Processes
*/

int					init_process(t_vm *vm);
t_pro				*new_pro_from_champ(t_champ champ, t_vm vm);
t_pro				*new_pro_from_pro(t_pro pro, t_vm vm);
void				free_pro(t_vm *vm);
void				increment_pc(int increment, t_pro *pro, t_vm *vm);

int					have_winner(t_vm vm);
t_champ				*winner(t_vm vm);
int					have_active_pro(t_vm *vm);

void				exec_pro(t_pro *pro, t_vm *vm);
void				goto_next_operation(t_pro *pro, t_vm *vm);

/*
 ** REG
*/

int					num_at_reg(t_vm vm, int pos, size_t size);
void				set_num_at_reg(t_vm *vm, t_pro pro, int reg_pos, unsigned int reg);

/*
 ** OPERATIONS
*/

int					op_size(int op_code, int oct_code, t_vm vm);
int					*params(t_pro pro, t_vm vm, int *p);
int					param_type(int oct_code, int n);
int     			incorrect_param(t_pro pro, t_vm vm, int op_code);
int     			ft_mod(int a, int b);
void				new_op(t_pro *pro, t_vm *vm);

void				ft_live(t_pro *pro, t_vm *vm);
void				ft_ld(t_pro *pro, t_vm *vm);
void				ft_st(t_pro *pro, t_vm *vm);
void				ft_add(t_pro *pro, t_vm *vm);
void				ft_sub(t_pro *pro, t_vm *vm);
void				ft_and(t_pro *pro, t_vm *vm);
void				ft_or(t_pro *pro, t_vm *vm);
void				ft_xor(t_pro *pro, t_vm *vm);
void				ft_zjmp(t_pro *pro, t_vm *vm);
void				ft_ldi(t_pro *pro, t_vm *vm);
void				ft_sti(t_pro *pro, t_vm *vm);
void				ft_fork(t_pro *pro, t_vm *vm);
void				ft_lld(t_pro *pro, t_vm *vm);
void				ft_lldi(t_pro *pro, t_vm *vm);
void				ft_lfork(t_pro *pro, t_vm *vm);
void				ft_aff(t_pro *pro, t_vm *vm);

/*
 ** UI
*/

# define 			COLOR_GRAY 8
# define			INFO_LINE 2
# define			CHAMPS_LINE INFO_LINE + 12


int					init_ui(t_vm *vm);
void				end_ui(void);

void				ui_draw_reg(t_vm *vm, int color, int reg_pos, int inverted);
void				ui_display_reg(t_vm *vm);
void				ui_display_pro(t_vm *vm);
void				ui_display_infos(t_vm vm);
void				ui_display_champs(t_vm vm);
void				ui_die_pro(t_vm *vm, t_pro *pro, int pro_index);

void				ui_update_if_needed(t_vm *vm);
void				ui_update_reg(t_vm *vm, t_pro pro, int reg_pos);
void				ui_update_info(t_vm vm);
void				ui_update_champs(t_vm vm);
void				ui_update_reg_bold(t_vm *vm);

void				ui_print_left_center(t_win *w, int line, int len, char *f, ...);
void				ui_print_right_center(t_win *w, int line, char *f, ...);
void				ui_print_title(t_win *w, int line, char *f, ...);

void				need_pro_display(t_vm *vm);
void				need_champ_display(t_vm *vm);

#endif
