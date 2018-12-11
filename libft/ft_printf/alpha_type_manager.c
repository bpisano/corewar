/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alpha_type_manager.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:53:00 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 14:59:54 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		alpha_type(t_arg *arg)
{
	int		i;
	char	*types;

	i = 0;
	types = "sScCp";
	while (types[i])
	{
		if (types[i] == arg->type)
			return (1);
		i++;
	}
	return (0);
}

int		char_type(t_arg *arg)
{
	return (arg->type == 'c' || arg->type == 'C');
}

int		string_type(t_arg *arg)
{
	return (arg->type == 's' || arg->type == 'S');
}

int		point_type(t_arg *arg)
{
	return (arg->type == 'p');
}

int		percent_type(t_arg *arg)
{
	return (arg->type == '%');
}
