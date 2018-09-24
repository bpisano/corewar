/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compiler.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:57:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/24 18:52:26 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef COMPILER_H
# define COMPILER_H

#include "libft.h"

/*
 ** BINARY
*/

char	*new_bin();
char	add_to_bin(char **bin, char b);
char	add_str_to_bin(char **bin, char *str);
void	free_binary(char **bin);

/*
 ** READ_FILE
*/

char**  ReadFile(char *filename);

#endif
