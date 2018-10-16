/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compiler.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:57:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:39:44 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COMPILER_H
# define COMPILER_H

# include "libft.h"
# include "op.h"

# define EMPTY_CHAR 57

/*
 ** ERROR
*/

void	display_error(int error);

/*
 ** MEMORY
*/

void	free_split(char ***split);

/*
 ** BINARY
*/

int		**new_bin();
int		bin_len(int **bin);
int		bin_size(int **bin);
int		add_bin_line(int ***bin);
int		add_bin_int(int ***bin, int n, size_t oct);
void	add_bin_pos(int *bin, int n, size_t oct);
void	free_bin(int ***bin);
void	print_bin(int **bin);

/*
 ** FILE
*/

char	**read_file(int fd);
void	free_file_lines(char ***tab);
int		is_comment(char *str);
char	*no_comment(char *str);
void	str_replace(char **str, char c, char rep);

int		corewar_alpha(char c);
int		str_start_by(char *str, char *start);
int		label_offset(char *str);
int		have_two_separator(char *line);
int		verify_syntax(char **line);

/*
 ** WRITE
*/

char	*cor_name(char *str);
void	write_header(t_head head, int fd);
void	write_bin(int **bin, int fd);

/*
 ** HEADER
*/

void	set_head_name(t_head *head, char *name);
void	set_head_comment(t_head *head, char *com);
int		set_header(t_head *head, char **file_lines);

/*
 ** COMPILER
*/

int		ft_emptychar(char *str);

int		core_text(int ***bin, char **file_lines);
int     ft_somestrchr(char *str1, char *str2);

char	***new_cmd_lines();
int		add_cmd_line(char ****cmd_lines, char *line);
void	free_cmd(char ****cmd);

int     add_lab_list(char *name, int pos, int **bin, t_label ***label);
int		fill_bin_lab(t_label **label, t_lab *lab, int **bin);
int		handle_op(t_pos data, t_op *op_tab, int ***bin, t_lab ***lab);

int		op_type(char *op);
int		param_bin(int op_code);
int		is_label(char *str);
void	free_label(t_label *lab);
int		is_op(char *str, t_op *op_tab);
int		ft_str_is_number(char *str);
t_op	*initialisation(t_lab ***lab, t_pos *data, char **file_lines);
int		free_struct(t_pos data, t_op *op, t_lab **lab, int i);
int	    free_struct_label(t_label **label, int i);

#endif
