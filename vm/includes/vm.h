/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 15:37:11 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 17:50:16 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "corewar.h"
# include "op.h"
# include <ncurses.h>

# define ERROR_N1	"ERROR : Number needed after -n flag\n"
# define ERROR_D1	"ERROR : Number needed after -d flag\n"
# define ERROR_N2	"ERROR : Champs needed after -n flag\n"
# define ERROR_N3	"ERROR : Num after -n (%d) flag must be greater than 0\n"
# define ERROR_N4	"ERROR : Num after -n (%d) flag must be less than 1000\n"
# define ERROR_D2	"ERROR : Cannot use multiple -d flag\n"
# define ERROR_D3	"ERROR : Cannot use -d flag with a negative number\n"
# define ERROR_OPEN	"ERROR : \"%s\" cannot be opened or does not exist\n"
# define ERROR_NUMB	"ERROR : 1 to %d champions needed\n"
# define ERROR_ASM	"ERROR : Cannot run .s file. Execute \"./asm %s\" first\n"
# define ERROR_F1	"ERROR : Missing flag. Use -a, -d, -i or -n\n"
# define ERROR_F2	"ERROR : flag \"%s\" is not handle\n"
# define ERROR_FILE	"ERROR : \"%s\" is not a file\n"
# define ERROR_COR	"ERROR : \"%s\" is not a .cor\n"
# define ERROR_MALL	"ERROR : Memory allocation\n"
# define ERROR_0	"ERROR : First byte must be 0x00\n"
# define ERROR_MGC	"ERROR : Invalid COREWAR_EXEC_MAGIC\n"
# define ERROR_CHMP	"ERROR : Invalid parameter number %d: \"%s\"\n"
# define ERROR_NAME	"ERROR : Champion number %d name's is incorrect\n"
# define ERROR_READ	"ERROR : Invalid header size\n"
# define ERROR_CONT	"ERROR : Too large content\n"
# define ERROR_EMPT "ERROR : Empty content\n"
# define ERROR_SIZE	"ERROR : Bad content size\n"
# define ERROR_COM	"ERROR : Comment is too long\n"
# define ERROR_NBR	"ERROR : Player number %d is already used\n"
# define ERROR_UIAF "ERROR : Cannot use both -i and -a\n"

# define LIVE_TXT	"un processus dit que le joueur %d(%s) est en vie\n"
# define WIN_TXT	"le joueur %d(%s) a gagne\n"

# define NEW_OP 256

# define COLOR_GRAY 8
# define SETTINGS_LINE 2
# define INFO_LINE SETTINGS_LINE + 5
# define CHAMPS_LINE INFO_LINE + 12

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
	char			inverted[MEM_SIZE];

	int				need_pro_disp;
	int				need_cha_disp;

	char			paused;
	int				cycle_sec;

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
	unsigned char	last_champ;

	int				dump;
	char			use_ui;
	char			aff;
	unsigned int	nbr_pro;
	unsigned int	nbr_pro_alive;

	t_champ			champs[MAX_PLAYERS];
	t_pro			**pro;
	t_op			*op_tab;
	t_ui			*ui;
}					t_vm;

/*
 ** ERROR
*/

void				vm_usage(void);

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
void				swap_reg(t_vm *vm, unsigned int c);

int					exec_vm(t_vm *vm);
void				free_vm(t_vm *vm, int ui);
void				print_vm(t_vm vm);

/*
 ** Processes
*/

int					init_process(t_vm *vm);
t_pro				*new_pro_from_champ(t_champ champ, t_vm vm);
t_pro				*new_pro_from_pro(t_pro pro, t_vm vm);
void				free_pro(t_vm *vm);
void				increment_pc(int increment, t_pro *pro, t_vm *vm);

int					have_winner(t_vm vm);
t_champ				winner(t_vm vm);
int					have_active_pro(t_vm *vm);

void				exec_pro(t_pro *pro, t_vm *vm);
void				goto_next_operation(t_pro *pro, t_vm *vm);

/*
 ** REG
*/

int					num_at_reg(t_vm vm, int pos, size_t size);
void				set_num_at_reg(t_vm *vm, t_pro pro, int reg_pos,
									unsigned int reg);

/*
 ** OPERATIONS
*/

int					op_size(int op_code, int oct_code, t_vm vm);
int					*params(t_pro pro, t_vm vm, int *p);
int					param_type(int oct_code, int n);
int					incorrect_param(t_pro pro, t_vm vm, int op_code);
int					ft_mod(int a, int b);
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

int					init_ui(t_vm *vm);
void				end_ui(void);

void				wait_key_event(t_vm *vm);
void				ui_display_pause_title(t_vm vm);
void				ui_display_run_title(t_vm vm);

void				ui_draw_reg(t_vm *vm, int color, int reg_pos, int inverted);
void				ui_display_reg(t_vm *vm);
void				ui_display_pro(t_vm *vm);
void				ui_display_infos(t_vm vm);
void				ui_display_champs(t_vm vm);
void				ui_display_settings(t_vm vm);
void				ui_display_winner(t_vm vm);
void				ui_die_pro(t_vm *vm, t_pro *pro);

void				ui_update_if_needed(t_vm *vm);
void				ui_update_reg(t_vm *vm, t_pro pro, int reg_pos);
void				ui_update_info(t_vm vm);
void				ui_update_champs(t_vm vm);
void				ui_update_settings(t_vm vm);
void				ui_update_reg_bold(t_vm *vm);

void				ui_print_left_center(t_win *w, int line, int len,
											char *f, ...);
void				ui_print_right_center(t_win *w, int line, char *f, ...);
void				ui_print_title(t_win *w, int line, char *f, ...);

void				need_pro_display(t_vm *vm);
void				need_champ_display(t_vm *vm);

#endif
