/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 10:48:27 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:07:13 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

static int		write_to_files(t_head head, int ***bin, char *file_name)
{
	if (!write_header(head, "test.cor"))
		return (0);
	print_bin(*bin);
	return (1);
}

static int		compile_lines(char **file_lines, int ***bin, char *name)
{
	int		prog_start;
	int		comp_error;
	t_head	head;

	if ((prog_start = set_header(&head, file_lines)) < 0)
	{
		display_error(prog_start);
		return (0);
	}
	if ((comp_error = core_text(bin, file_lines + prog_start)))
	{
		display_error(comp_error);
		return (0);
	}
	return (write_to_files(head, bin, name));
}

static int		verify_file(char *file_name, char ***file_lines, int ***bin)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		display_error(3);
		return (0);
	}
	if (!(*file_lines = read_file(fd)))
	{
		display_error(5);
		return (0);
	}
	if (!(*bin = new_bin()))
	{
		display_error(4);
		return (0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	int		i;
	char	**file_lines;
	int		**bin;

	if (argc < 2)
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (!verify_file(argv[i], &file_lines, &bin))
		{
			free_file_lines(&file_lines);
			return (0);
		}
		if (!compile_lines(file_lines, &bin, argv[i]))
		{
			free_bin(&bin);
			free_file_lines(&file_lines);
			return (0);
		}
	}
	free_bin(&bin);
	free_file_lines(&file_lines);
	ft_printf("Successfuly compiled.\n");
	return (0);
}
