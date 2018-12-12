/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fnct.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 20:06:22 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 18:39:34 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

char	ft_str_is_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (!(*str));
}

char	ft_somestrchr(char *str1, char *str2)
{
	int		i;

	i = -1;
	while (str1[++i])
		if (!ft_strchr(str2, str1[i]))
			return (0);
	return (1);
}

int		fill_bin_lab(t_label **label, t_lab *lab, int **bin)
{
	int		i;
	int		tot;

	i = -1;
	tot = 0;
	while (++i < lab->i_for_bin)
		tot += bin[i][0];
	i = -1;
	while (label[++i])
	{
		if (!ft_strcmp(label[i]->name, lab->name + 2))
		{
			add_bin_pos(&bin[lab->i_for_bin][lab->pos], label[i]->pos - tot,
			lab->oct);
			return (0);
		}
		else if (!ft_strcmp(label[i]->name, lab->name + 1))
		{
			add_bin_pos(&bin[lab->i_for_bin][lab->pos], label[i]->pos - tot,
			2);
			return (0);
		}
	}
	return (ft_error(ERROR_LABEL, lab->name));
}

char	add_lab_list(char *name, int pos, int **bin, t_label ***label)
{
	int		i;

	i = -1;
	while (label[0][++i])
		;
	if (!(*label = realloc(*label, sizeof(t_label*) * (i + 2))))
		return (0);
	if (!(label[0][i] = malloc(sizeof(t_label))))
		return (0);
	label[0][i]->name = name;
	label[0][i]->name[ft_strlen(label[0][i]->name) - 1] = 0;
	label[0][i]->pos = pos;
	label[0][i + 1] = 0;
	return (1);
}

char	is_label(char *str)
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
