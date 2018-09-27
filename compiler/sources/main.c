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

static int		write_to_files(t_head head, t_bin *bin, char *file_name)
{
	if (!write_header(head, "test.cor"))
	{
		free_bin(bin);
		return (0);
	}
	free_bin(bin);
	return (1);
}

static int		compile_file_lines(char **file_lines, t_bin *bin, char *name)
{
	int		prog_start;
	t_head	head;

	if ((prog_start = set_header(&head, file_lines)) < 0)
	{
		display_error(prog_start);
		return (0);
	}
	free_file_lines(&file_lines);
	return (write_to_files(head, bin, name));
}

static int		verify_file(char *file_name)
{
	char	**file_lines;
	t_bin	bin;

	if (!(file_lines = read_file(file_name)))
	{
		display_error(3);
		return (0);
	}
	if (!init_bin(&bin))
	{
		display_error(4);
		free_file_lines(&file_lines);
		return (0);
	}
	if (!compile_file_lines(file_lines, &bin, file_name))
	{
		free_file_lines(&file_lines);
		free_bin(&bin);
		return (0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!verify_file(argv[i]))
			return (0);
	}
	return (0);
}
