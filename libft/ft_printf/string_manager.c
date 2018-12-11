/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:03:52 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 14:06:38 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_type(char c)
{
	int		i;
	char	*types;

	i = 0;
	types = "sSpdDioOuUxXcC%";
	while (types[i])
	{
		if (types[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_flag(char c)
{
	int		i;
	char	*flags;

	i = 0;
	flags = "+-#0 ";
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_modifier(char c)
{
	int		i;
	char	*modifiers;

	i = 0;
	modifiers = "hljz";
	while (modifiers[i])
	{
		if (modifiers[i] == c)
			return (1);
		i++;
	}
	return (0);
}
