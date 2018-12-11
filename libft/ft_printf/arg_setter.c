/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg_setter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 13:58:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 15:54:17 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_flag(t_arg **arg, char f, int *i)
{
	if (!flag(*arg, f))
		add_flag(*arg, f);
	*i += 1;
}

static void		set_f_width(t_arg **arg, char *format, va_list params, int *i)
{
	int		j;

	if (format[0] == '*')
	{
		(*arg)->f_width = va_arg(params, int);
		if ((*arg)->f_width < 0)
		{
			(*arg)->f_width = -((*arg)->f_width);
			add_flag((*arg), '-');
		}
		*i += 1;
		return ;
	}
	j = 0;
	(*arg)->f_width = 0;
	while (ft_isdigit(format[j]))
	{
		(*arg)->f_width = (*arg)->f_width * 10 + format[j] - 48;
		j++;
	}
	*i += j;
}

static void		set_precision(t_arg **arg, char *format, va_list params, int *i)
{
	int		j;

	if (format[0] == '*')
	{
		(*arg)->prec = va_arg(params, int);
		if ((*arg)->prec < 0)
			(*arg)->prec = -1;
		*i += 2;
		return ;
	}
	j = 0;
	(*arg)->prec = 0;
	while (ft_isdigit(format[j]))
	{
		(*arg)->prec = (*arg)->prec * 10 + format[j] - 48;
		j++;
	}
	*i += j + 1;
}

static void		set_modifier(t_arg **arg, char *format, int *i)
{
	int		j;
	int		mod;

	j = 0;
	mod = 0;
	while (is_modifier(format[j]) && mod < 2)
	{
		mod++;
		j++;
	}
	(*arg)->modifier = ft_strsub(format, 0, mod);
	*i += j;
}

t_arg			*get_arg(char *format, va_list params, int i)
{
	t_arg	*arg;

	if (!(arg = new_arg()))
		return (NULL);
	while (!is_type(format[i]) && format[i])
	{
		if (is_flag(format[i]))
			set_flag(&arg, format[i], &i);
		else if ((ft_isdigit(format[i]) && format[i] != 0) || format[i] == '*')
			set_f_width(&arg, format + i, params, &i);
		else if (format[i] == '.')
			set_precision(&arg, format + i + 1, params, &i);
		else if (is_modifier(format[i]))
			set_modifier(&arg, format + i, &i);
		else
			break ;
	}
	if ((!is_type(format[i]) && !ft_isascii(format[i])) || !format[i])
	{
		free_arg(arg);
		return (NULL);
	}
	set_arg_value(&arg, format[i], i, params);
	return (arg);
}
