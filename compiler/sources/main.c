/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 10:48:27 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 12:34:18 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "compiler.h"

int		main(int argc, char **argv)
{
	int 	i;
	char	*bin;
	char	**file_lines;
	int		comp_error;
	
	i = 0;
	while (++i < argc)
	{
		if (!(file_lines = read_file(argv[i])))
		{
			display_error(3);
			continue ;
		}
		if (!(bin = new_bin()))
		{
			display_error(4);
			continue ;
		}
		if ((comp_error = add_head_to_bin(&bin, file_lines)) != 0)
		{
			display_error(comp_error);
			continue;
		}
	}
	return (0);
}
