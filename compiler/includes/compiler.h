/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compiler.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:57:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/27 22:24:56 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COMPILER_H
# define COMPILER_H

#include "libft.h"
#include "op.h"

/*
 ** ERROR
*/

void	display_error(int error);

/*
 ** BINARY
*/

int		**new_bin();
int		bin_len(int **bin);
int		add_bin_line(int ***bin);
int		add_bin_int(int ***bin, int n, size_t oct);
void	free_bin(int ***bin);
void	print_bin(int **bin);

/*
 ** FILE
*/

char	**read_file(char *filename);
void	free_file_lines(char ***tab);
int		is_comment(char *str);
char	*no_comment(char *str);
void	str_replace(char **str, char c, char rep);

/*
 ** WRITE
*/

char	*file_name(char *arg);
int		write_header(t_head head, char *file_name);
int		write_bin(int *bin, char *file_name);

/*
 ** HEADER
*/

void	set_head_name(t_head *head, char *name);
void	set_head_comment(t_head *head, char *com);
int		set_header(t_head *head, char **file_lines);

/*
 ** COMPILER
*/

int     ft_somestrchr(char *str1, char *str2);

char	***new_cmd_lines();
int		add_cmd_line(char ****cmd_lines);

#endif
