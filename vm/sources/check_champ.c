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
		return (ft_error(ERROR_0));
	if (!(str = ft_itoa_base(COREWAR_EXEC_MAGIC, 16)))
		return (ft_error(ERROR_MALL));
	if (ft_strlen(str) % 2)
	{
		free(str);
		return (ft_error(ERROR_MGC));
	}
	*i = 0;
	j = 0;
	while (str[j])
	{
		if ((unsigned char)line[++(*i)] != convert_hexa_int(str[j], str[j + 1]))
		{
			free(str);
			return (ft_error(ERROR_MGC));
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
	while (line[++(*i)])
	{
		if (j == PROG_NAME_LENGTH + 1)
			return (ft_error(ERROR_NAME, k + 1));
		vm->champs[k].name[j] = line[*i];
		j++;
	}
	vm->champs[k].name[j] = 0;
	vm->champs[k].last_live = 0;
	vm->champs[k].cur_live = 0;
	vm->champs[k].pc = k * MEM_SIZE / vm->nbr_champs;
	vm->champs[k].live = 0;
	return (0);
}

int		check_comment(char *line, t_vm *vm, int k)
{
	int		i;
	int		j;

	i = 0x8b;
	j = -1;
	while (line[++i] && j < COMMENT_LENGTH)
		vm->champs[k].comment[++j] = line[i];
	if (j >= COMMENT_LENGTH)
		return (ft_error(ERROR_COM));
	vm->champs[k].comment[j + 1] = 0;
	return (0);
}

int		init_champ(char *line, t_vm *vm, char *name)
{
	int		fd;

	if ((fd = ft_strlen(name)) >= 2 && !ft_strcmp(name + fd - 2, ".s"))
		return (ft_error(ERROR_ASM, name));
	if ((fd = ft_strlen(name)) < 4 || ft_strcmp(name + fd - 4, ".cor"))
		return (ft_error(ERROR_COR, name));
	if ((fd = open(name, O_RDONLY)) == -1)
		return (ft_error(ERROR_OPEN, name));
	if (read(fd, line, HEADER_SIZE) < HEADER_SIZE)
		return (ft_error(ERROR_READ));
	if ((unsigned char)line[SIZE_CHAMP] * 256 +
	(unsigned char)line[SIZE_CHAMP + 1] > CHAMP_MAX_SIZE)
		return (ft_error(ERROR_CONT));
	if ((unsigned char)line[SIZE_CHAMP] * 256 +
	(unsigned char)line[SIZE_CHAMP + 1] == 0)
		return (ft_error(ERROR_EMPT));
	if (read(fd, line + HEADER_SIZE, (unsigned char)line[SIZE_CHAMP]
	* 256 + (unsigned char)line[SIZE_CHAMP + 1] + 1) !=
	(unsigned char)line[SIZE_CHAMP] * 256 + (unsigned char)line[SIZE_CHAMP + 1])
		return (ft_error(ERROR_SIZE));
	return (0);
}

int		invalid_champ(char *name, t_vm *vm, char *number)
{
	int		j;
	char	line[HEADER_SIZE + CHAMP_MAX_SIZE + 1];

	if (init_champ(line, vm, name))
		return (1);
	if (check_magic(line, vm, &j) || check_name(line, vm, &j, vm->last_champ) ||
	check_comment(line, vm, vm->last_champ))
		return (1);
	j = -1;
	while (++j < (unsigned char)line[SIZE_CHAMP] * 256 +
		(unsigned char)line[SIZE_CHAMP + 1])
		vm->reg[j + (vm->last_champ * MEM_SIZE / vm->nbr_champs)] =
		line[HEADER_SIZE + j];
	vm->champs[vm->last_champ].size = (unsigned char)line[SIZE_CHAMP] * 256
	+ (unsigned char)line[SIZE_CHAMP + 1];
	if (handle_number(vm, number, vm->last_champ))
		return (ft_error(ERROR_NBR, ft_atoi(number)));
	vm->last_champ++;
	return (0);
}
