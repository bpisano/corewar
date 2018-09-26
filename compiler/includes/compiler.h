/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compiler.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:57:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 13:00:20 by anamsell    ###    #+. /#+    ###.fr     */
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

int		*new_bin();
int		add_num_to_bin(int **bin, size_t params, ...);
int		add_int_to_bin(int **bin, int n);
int		add_str_to_bin(int **bin, char *str);
void	free_binary(int **bin);

/*
 ** FILE
*/

char	**read_file(char *filename);
void	free_file_lines(char ***tab);

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

#endif
