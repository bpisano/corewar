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

static int		compile_file_lines(char **file_lines, int **bin)
{
	int		error;
	
	if ((error = add_head_to_bin(bin, file_lines)))
	{
		display_error(error);
		return (0);
	}
	free_file_lines(&file_lines);
	free_binary(bin);
	
	int i = -1;
	while (++i <= (*bin)[0])
		printf("hex: %#x\n", (*bin)[i]);
	printf("%d\n", write_bin(*bin, "test.cor"));
	return (1);
}

static int		verify_file(char *file_name)
{
	char	**file_lines;
	int		*bin;
	
	if (!(file_lines = read_file(file_name)))
	{
		display_error(3);
		return (0);
	}
	if (!(bin = new_bin()))
	{
		display_error(4);
		free_file_lines(&file_lines);
		return (0);
	}
	if (!compile_file_lines(file_lines, &bin))
	{
		free_file_lines(&file_lines);
		free_binary(&bin);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int 	i;
	
	i = 0;
	while (++i < argc)
	{
		if (!verify_file(argv[i]))
			return (0);
	}
	return (0);
}
