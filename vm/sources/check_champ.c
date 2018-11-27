/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_champ.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/21 15:16:52 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:19:56 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		check_magic(char *line, t_vm *vm, int *i)
{
	char	*str;
	int		j;

	if (line[0])
		return (ft_printf(ERROR_0));
	if (!(str = ft_itoa_base(COREWAR_EXEC_MAGIC, 16)))
		return (ft_printf(ERROR_MALL));
	if (ft_strlen(str) % 2)
	{
		free(str);
		return (ft_printf(ERROR_MGC));
	}
	*i = 0;
	j = 0;
	while (str[j])
	{
		if ((unsigned char)line[++(*i)] != convert_hexa_int(str[j], str[j + 1]))
		{
			free(str);
			return (ft_printf(ERROR_MGC));
		}
		j += 2;
	}
	free(str);
	return (0);
}

int		check_name(char *line, t_vm *vm, int *i, int k)
{
	int		j;

	j = 0;
	if (!(vm->champs[k] = malloc(sizeof(t_champ))))
		return (ft_printf(ERROR_MALL));
	vm->champs[k + 1] = 0;
	while (line[++(*i)])
	{
		if (j == PROG_NAME_LENGTH + 1)
			return (ft_printf(ERROR_NAME, k + 1));
		vm->champs[k]->name[j] = line[*i];
		j++;
	}
	vm->champs[k]->name[j] = 0;
	vm->champs[k]->last_live = 0;
	vm->champs[k]->cur_live = 0;
	vm->champs[k]->pc = k * MEM_SIZE / vm->nbr_champs;
	vm->champs[k]->live = 0;
	return (0);
}

int		check_comment(char *line, t_vm *vm, int k)
{
	int		i;
	int		j;

	i = 0x8b;
	j = -1;
	while (line[++i] && j < COMMENT_LENGTH)
		vm->champs[k]->comment[++j] = line[i];
	if (j >= COMMENT_LENGTH)
		return (ft_printf(ERROR_COM));
	vm->champs[k]->comment[j + 1] = 0;
	return (0);
}

int		init_champ(char *line, t_vm *vm, char *name)
{
	int		fd;

	if ((fd = ft_strlen(name)) >= 2 && !ft_strcmp(name + fd - 2, ".s"))
		return (ft_printf(ERROR_ASM, name, name));
	if ((fd = ft_strlen(name)) < 4 || ft_strcmp(name + fd - 4, ".cor"))
		return (ft_printf(ERROR_COR, name));
	if ((fd = open(name, O_RDONLY)) == -1)
		return (ft_printf(ERROR_OPEN, name));
	if (read(fd, line, HEADER_SIZE) < HEADER_SIZE)
		return (ft_printf(ERROR_READ));
	if ((unsigned char)line[0x8a] * 256 + (unsigned char)line[0x8b]
	> CHAMP_MAX_SIZE)
		return (ft_printf(ERROR_CONT));
	if (read(fd, line + HEADER_SIZE, (unsigned char)line[0x8a] * 256
	+ (unsigned char)line[0x8b] + 1) !=
	(unsigned char)line[0x8a] * 256 + (unsigned char)line[0x8b])
		return (ft_printf(ERROR_SIZE, (unsigned char)line[0x8b]));
	return (0);
}

int		invalid_champ(char *name, t_vm *vm, char *number)
{
	int		i;
	int		j;
	char	line[HEADER_SIZE + CHAMP_MAX_SIZE + 1];

	i = -1;
	while (vm->champs[++i])
		;
	if (init_champ(line, vm, name))
		return (free_chmp(vm));
	if (check_magic(line, vm, &j) || check_name(line, vm, &j, i) ||
	check_comment(line, vm, i))
		return (free_chmp(vm));
	j = -1;
	while (++j < (unsigned char)line[0x8a] * 256 + (unsigned char)line[0x8b])
		vm->reg[j + (i * MEM_SIZE / vm->nbr_champs)] =
		line[HEADER_SIZE + j];
	if (handle_number(vm, number, i))
		return (ft_printf(ERROR_NBR, ft_atoi(number)) && free_chmp(vm));
	return (0);
}
