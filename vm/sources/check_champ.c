/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_champ.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/21 15:16:52 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 11:37:30 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

char	*ft_str_join_free(char *str1, char *str2)
{
	char	*join;

	if (!str1 || !str2)
		return (0);
	if (!(join = malloc(ft_strlen(str1) + ft_strlen(str2) + 1)))
		return (0);
	ft_strcpy(join, str1);
	ft_strcat(join, str2);
	free(str1);
	free(str2);
	return (join);
}


int		check_name(char **line, t_vm *vm)
{

}

int		valid_champ(char *name, t_vm *vm, char *number)
{
	int		fd;
	char	*line;
	char 	*new_line;

	if ((fd = ft_strlen(name)) >= 2 && !ft_strcmp(name + fd - 2, ".s"))
		return (ft_printf(ERROR_ASM, name, name));
	if ((fd = ft_strlen(name)) < 4 || ft_strcmp(name + fd - 4, ".cor"))
		return (ft_printf(ERROR_COR, name));
	if ((fd = open(name, O_RDONLY)) == -1)
		return (ft_printf(ERROR_OPEN, name));
	while (get_next_line(fd, &new_line) > 0)
		if (!(line = ft_str_join_free(line, new_line)))
			return (ft_printf(ERROR_MALL));
	if (check_name(&line, vm) || check_comment(&line, vm) || check_size(&line, vm) || check_content(&line, vm))
	{
		free(line);
		fd =-1;
		while (vm->champs[++fd])
			free(vm->champs[fd]);
		return (1);
	}
	free(line);
	return (0);
}
