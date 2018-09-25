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
int		add_str_to_bin(int **bin, char *str);
void	free_binary(int **bin);

/*
 ** READ_FILE
*/

char	**read_file(char *filename);
void	free_file_lines(char ***tab);

/*
 ** HEADER
*/

void	init_head(t_head *head);
void	set_head_name(t_head *head, char *name);
void	set_head_comment(t_head *head, char *com);
void	set_head_to_bin(int **bin, t_head head);

int		add_head_to_bin(int **bin, char **file_lines);

#endif
