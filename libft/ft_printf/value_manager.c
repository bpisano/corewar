/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   value_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:38:43 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 17:42:01 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	uarg_v(t_arg *arg)
{
	if (arg->type == 'U' || arg->type == 'O' || point_type(arg))
		return ((arg->value)->ulong);
	if (!(arg->modifier))
		return ((arg->value)->uint);
	if (ft_strcmp(arg->modifier, "hh") == 0)
		return (((arg->value)->uchar));
	if (ft_strcmp(arg->modifier, "h") == 0)
		return (((arg->value)->ushort));
	if (ft_strcmp(arg->modifier, "l") == 0)
		return (((arg->value)->ulong));
	if (ft_strcmp(arg->modifier, "ll") == 0)
		return (((arg->value)->ullong));
	if (ft_strcmp(arg->modifier, "j") == 0)
		return (((arg->value)->uintmax));
	if (ft_strcmp(arg->modifier, "z") == 0)
		return (((arg->value)->sizet));
	return ((arg->value)->ullong);
}

long long			arg_v(t_arg *arg)
{
	if (arg->type == 'D' || arg->type == 'X' || arg->type == 'O')
		return ((arg->value)->slong);
	if (!(arg->modifier))
		return ((arg->value)->sint);
	if (ft_strcmp(arg->modifier, "hh") == 0)
		return (((arg->value)->schar));
	if (ft_strcmp(arg->modifier, "h") == 0)
		return (((arg->value)->sshort));
	if (ft_strcmp(arg->modifier, "l") == 0)
		return (((arg->value)->slong));
	if (ft_strcmp(arg->modifier, "ll") == 0)
		return (((arg->value)->sllong));
	if (ft_strcmp(arg->modifier, "j") == 0)
		return (((arg->value)->sintmax));
	if (ft_strcmp(arg->modifier, "z") == 0)
		return (((arg->value)->sizet));
	return ((arg->value)->sllong);
}

void				set_arg_value(
		t_arg **arg, char type, int offset, va_list params)
{
	(*arg)->offset = offset;
	if (!is_type(type) && ft_isascii(type))
	{
		(*arg)->type = 'c';
		((*arg)->value)->ullong = type;
		return ;
	}
	(*arg)->type = type;
	if (percent_type(*arg))
		((*arg)->value)->string = "%";
	else if (string_type(*arg))
		((*arg)->value)->string = va_arg(params, char *);
	else if (!int_type(*arg))
		((*arg)->value)->ullong = va_arg(params, unsigned long long);
	else
		((*arg)->value)->sllong = va_arg(params, long long);
}
