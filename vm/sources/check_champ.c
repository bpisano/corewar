/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_champ.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/21 15:16:52 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 23:12:51 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		check_magic(char *line, t_vm *vm, int *i)
{
	char	*str;
	int		j;

	*i = 0;
	if (line[*i])
	{
		ft_printf("%c\n",line[*i]);
		return (ft_printf(ERROR_0));
	}
	if (!(str = ft_itoa_base(COREWAR_EXEC_MAGIC, 16)))
		return (ft_printf(ERROR_MALL));
	if (ft_strlen(str) % 2)
	{
		free(str);
		return (ft_printf(ERROR_MGC));
	}
	*i += 1;
	j = 0;
	while (str[j])
	{
		if (line[*i] != (unsigned char)convert_hexa_int(str[j], str[j + 1]))
			return (ft_printf(ERROR_MGC));
		j += 2;
		*i += 1;
	}
	free(str);
	return(1);
}

int		check_name(char *line, t_vm *vm, int *i)
{
	int		j;
	int		k;

	j = 0;
	k = -1;
	while (vm->champs[++k])
		;
	if (!(vm->champs[k] = malloc(sizeof(t_champ))))
		return (ft_printf(ERROR_MALL));
	vm->champs[k + 1] = 0;
	while (line[*i])
	{
		if (j == PROG_NAME_LENGTH + 1)
			return (ft_printf(ERROR_NAME), k + 1);
		vm->champs[k]->name[j] = line[*i];
		j++;
		(*i)++;
	}
	vm->champs[k]->name[j] = 0;
	return (0);
}

int		valid_champ(char *name, t_vm *vm, char *number)
{
	int		fd;
	char	line[HEADER_SIZE + CHAMP_MAX_SIZE];

	if ((fd = ft_strlen(name)) >= 2 && !ft_strcmp(name + fd - 2, ".s"))
		return (ft_printf(ERROR_ASM, name, name));
	if ((fd = ft_strlen(name)) < 4 || ft_strcmp(name + fd - 4, ".cor"))
		return (ft_printf(ERROR_COR, name));
	if ((fd = open(name, O_RDONLY)) == -1)
		return (ft_printf(ERROR_OPEN, name));
	if (read(fd, line, HEADER_SIZE) < HEADER_SIZE)
		return (ft_printf(ERROR_READ));
	if (read(fd, line + HEADER_SIZE, line[0x8a] * 256 + line[0x8b])
	< line[0x8a] * 256 + line[0x8b])
		return (ft_printf(ERROR_SIZE));
	fd = 0;
	if (check_magic(line, vm, &fd) || check_name(line, vm, &fd) ||
	check_comment(line, vm, &fd) || check_content(line, vm, &fd))
	{
		free(line);
		fd = -1;
		while (vm->champs[++fd])
			free(vm->champs[fd]);
		return (1);
	}
	free(line);
	return (0);
}
