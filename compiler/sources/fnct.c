/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fnct.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 20:06:22 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 17:08:03 by anamsell    ###    #+. /#+    ###.fr     */
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


int    add_lab_list(char *name, int pos, int **bin, t_label **label)
{
	while (label[0])
	{
		if (!(ft_strcmp(name, label[0]->name)))
			return (1);
		label[0] = label[0]->next;
	}
	if (!(label[0] = malloc(sizeof(t_label))))
		return (0);
	label[0]->name = name;
	printf ("%s\n", label[0]->name);
	label[0]->name[ft_strlen(label[0]->name) - 1] = 0;
	label[0]->pos = pos;
	label[0]->next = 0;
	return (1);
}

int		fill_bin_lab2(t_label *label, t_lab *lab, int pos)
{
	int		i;

	i = 0;
	printf ("%s\n",lab->name);
	while (label->name)
	{
		printf("\n%s\n",label->name);
		if (label->name == lab->name)
		{
			add_bin_pos(lab->pos, label->pos - pos, lab->oct);
			return (0);
		}
		label = label->next;
	}
	return (1);
}

int		fill_bin_lab(int *bin, t_label *label, t_lab **lab, int pos)
{
	int     i;

	i = -1;
	while (lab[++i])
	{
		if (lab[i]->pos == bin)
		{
			printf("label : %s, lab : %s\n",label->next->name, lab[i]->name);
			return (fill_bin_lab2(label, lab[i], pos));
		}
	}
	return (0);
}

int		is_label(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != LABEL_CHAR && str[i])
		if (!(ft_strchr(LABEL_CHARS, str[i])))
			return (0);
	if (str[i] != LABEL_CHAR || i == 0 || str[i + 1] != 0)
		return (0);
	return (1);
}
