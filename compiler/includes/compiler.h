/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compiler.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:57:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/24 17:48:50 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef COMPILER_H
# define COMPILER_H

#include "libft.h"

/*
 ** BINARY
*/

int		*new_bin();
int		add_to_bin(int **bin, int b);
int		*str_to_bin(char *str);
void	free_binary(int **bin);

#endif
