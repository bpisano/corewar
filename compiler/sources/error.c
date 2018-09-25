/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 19:34:47 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/24 19:35:07 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

static void		error(char *desc)
{
	ft_printf("ERROR: %s\n", desc);
}

void			display_error(int error)
{
	if (error == 1)
		error("Misssing champion name");
	else if (error == 2)
		error("Missing champion description");
	else
		ft_putstr("ERROR\n");
}
