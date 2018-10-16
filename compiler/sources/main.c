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
	char	*comp_name;
	int		fd;
	
	comp_name = cor_name(file_name);
	if ((fd = open(comp_name, O_RDWR | O_CREAT | O_TRUNC, 0777)) < 0)
	{
		display_error(3);
		return (0);
	}
	write_header(head, fd);
	write_bin(*bin, fd);
	print_bin(*bin);
	ft_printf("Successfuly compiled in %s\n", comp_name);
	free(comp_name);
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
	head.prog_size = bin_size(*bin);
	return (write_to_files(head, bin, name));
}

static int		verify_file(char *file_name, char ***file_lines, int ***bin)
{
	int		fd;

	if ((fd = open(file_name, O_RDWR)) < 0)
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
	return (0);
}
