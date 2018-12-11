/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   num_type_manager.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:52:03 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 14:58:34 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_type(t_arg *arg)
{
	int		i;
	char	*types;

	i = 0;
	types = "dDioOuUxX";
	while (types[i])
	{
		if (types[i] == arg->type)
			return (1);
		i++;
	}
	return (0);
}

int		int_type(t_arg *arg)
{
	return (arg->type == 'd' || arg->type == 'D' || arg->type == 'i');
}

int		uint_type(t_arg *arg)
{
	return (arg->type == 'u' || arg->type == 'U');
}

int		hex_type(t_arg *arg)
{
	return (arg->type == 'x' || arg->type == 'X');
}

int		oct_type(t_arg *arg)
{
	return (arg->type == 'o' || arg->type == 'O');
}
