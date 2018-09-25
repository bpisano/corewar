/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_gestion.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 10:55:54 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 12:34:14 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

int		*new_bin(void)
{
	int		*new;

	if (!(new = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	new[0] = 0;
	new[1] = 0;
	return (new);
}

int		add_int_to_bin(int **bin, int n)
{
	int		old_size;
	
	old_size = (*bin)[0];
	if (!(*bin = (int *)realloc(*bin, sizeof(int) * (old_size + 3))))
		return (0);
	(*bin)[0] = old_size + 1;
	(*bin)[old_size + 1] = n;
	(*bin)[old_size + 2] = 0;
	return (1);
}

int		add_str_to_bin(int **bin, char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (!add_num_to_bin(bin, 1, str[i]))
			return (0);
	return (1);
}

void	free_binary(int **binary)
{
	free(*binary);
}

int		add_num_to_bin(int **bin, size_t params, ...)
{
	int		i;
	int		old_size;
	va_list	args;

	i = -1;
	va_start(args, params);
	while (++i < (int)params)
	{
		old_size = (*bin)[0];
		if (!(*bin = (int *)realloc(*bin, sizeof(int) * (old_size + 3))))
		{
			va_end(args);
			return (0);
		}
		(*bin)[0] = old_size + 1;
		(*bin)[old_size + 1] = va_arg(args, int);
		(*bin)[old_size + 2] = 0;
	}
	va_end(args);
	return (1);
}
