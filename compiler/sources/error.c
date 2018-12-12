/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 19:34:47 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 10:19:50 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

static void		error_desc(char *desc)
{
	ft_error("ERROR: %s\n", desc);
}

void			display_error(int error)
{
	if (error == -1)
		error_desc("Missing champion name");
	else if (error == -2)
		error_desc("Missing champion comment");
	else if (error == -3)
		error_desc("Too much header parameters");
	else if (error == 3)
		error_desc("Incorrect file name");
	else if (error == 4)
		error_desc("Cannot allocate new binary");
	else if (error == 5)
		error_desc("Incorrect syntax");
}
