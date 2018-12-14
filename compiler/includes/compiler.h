/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compiler.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:57:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 00:02:24 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COMPILER_H
# define COMPILER_H

# include "libft.h"
# include "corewar.h"
# include "op.h"

# define ERROR_SEP		"ERROR line %d : Separator error\n~~~ %s ~~~\n"
# define ERROR_END_SEP	"ERROR line %d : Separator at end of line\n~~~ %s ~~~\n"
# define ERROR_ARG		"ERROR line %d : Wrong argument format\n~~~ %s ~~~\n"

# define ERROR_MALL		"ERROR : Memory allocation\n"
# define ER_OP			"ERROR : Invalid operator\n~~~ %s ~~~\n"
# define ERROR_OP_LEN	"ERROR : %d parameters are needed with %s operator\n"
# define ERROR_OP_TYPE	"ERROR : %s is not possible as arg no %d of %s\n"
# define ER_LA			"ERROR : Invalid label\n~~~ %s ~~~~\n"
# define ERROR_LABEL	"ERROR : Use of undeclared label\n~~~ %s ~~~\n"

# define PARAM		 	d.file[d.i][d.j], k + 1, d.file[d.i][d.j - k - 1]

/*
 ** STRUCTURE
*/

typedef struct		s_head
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_head;

typedef	struct		s_label
{
	char			*name;
	int				pos;

}					t_label;

typedef	struct		s_lab
{
	char			*name;
	int				oct;
	int				i;
	int				i_for_bin;
	int				j;
	int				pos;
}					t_lab;

typedef	struct		s_pos
{
	char			***file;
	int				i;
	int				j;
	int				decal;
}					t_pos;

typedef	struct		s_comp
{
	t_pos			data;
	t_op			*op_tab;
	t_lab			**lab;
}					t_comp;

/*
 ** ERROR
*/

void				display_error(int error);
void				compiler_usage(void);

/*
 ** MEMORY
*/

void				free_split(char **split);

/*
 ** BINARY
*/

int					**new_bin();
int					bin_len(int **bin);
int					bin_size(int **bin);
char				add_bin_line(int ***bin);
char				add_bin_int(int ***bin, int n, size_t oct);
void				add_bin_pos(int *bin, int n, size_t oct);
void				free_bin(int ***bin);

/*
 ** FILE
*/

char				**read_file(int fd);
char				is_comment(char *str);
char				*no_comment(char *str);
void				str_replace(char **str, char c, char rep);

char				corewar_alpha(char c);
char				str_start_by(char *str, char *start);
int					label_offset(char *str);
char				have_two_separator(char *line);
char				verify_syntax(char **line, int l);

/*
 ** WRITE
*/

char				*cor_name(char *str);
void				write_header(t_head head, int fd);
void				write_bin(int **bin, int fd);

/*
 ** HEADER
*/

void				set_head_name(t_head *head, char *name);
void				set_head_comment(t_head *head, char *com);
int					set_header(t_head *head, char **file_lines);

/*
 ** COMPILER
*/

int					core_text(int ***bin, char **file_lines);
char				ft_somestrchr(char *str1, char *str2);

char				***new_cmd_lines();
char				add_cmd_line(char ****cmd_lines, char *line);
char				add_lab_list(char *name, int pos, int **bin, t_label ***l);
int					fill_bin_lab(t_label **label, t_lab *lab, int **bin);
int					handle_op(t_pos data, t_op *op_tab, int ***bin, t_lab ***l);

char				op_type(char *op);
char				param_bin(int op_code);
char				is_label(char *str);
char				is_op(char *str, t_op *op_tab);
char				ft_str_is_number(char *str);
t_op				*initialisation(t_lab ***lab, t_pos *data, char **lines);
int					free_s(t_pos data, t_op *op, t_lab **lab, int i);
int					free_l(t_label **label, int i);

#endif
