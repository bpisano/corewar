/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fnct.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 20:06:22 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:55:13 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

int     ft_somestrchr(char *str1, char *str2)
{
	int     i;

	i = -1;

	while (str1[++i])
		if (!ft_strchr(str2, str1[i]))
			return (0);
	return (1);
}


int    add_lab_list(char *name, int pos, int **bin, t_label *lab)
{
	while (lab->name)
	{
		if (!(ft_strcmp(name, lab->name)))
			return (1);
		lab = lab->next;
	}
	lab->name = name;
	lab->pos = pos;
	if (!(lab->next = malloc(sizeof(lab))))
		return (0);
	lab->next->name = 0;
	return (1);
}

int     fill_bin_lab(int *bin, char **line, t_label lab, int pos)
{
	int     i;

	i = 0;
	while (!(line[i][0] == DIRECT_CHAR && line[i][1] == LABEL_CHAR))
		i++;
	while (lab.name)
	{
		if (!(ft_strcmp(lab.name, &line[i][2])))
		{
			printf("lab pos : %d  pos : %d\n", lab.pos, pos);
			*bin = lab.pos - pos;
			return (1);
		}
		lab = *lab.next;
	}
	return (0);
}

int		is_label(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != ':' && str[i])
		if (!(ft_strchr(LABEL_CHARS, str[i])))
			return (0);
	if (str[i] != ':' || i == 0 || str[i + 1] != 0)
		return (0);
	return (1);
}
