/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fnc.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <anamsell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 23:29:32 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 00:31:17 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vm.h"

int		convert_hexa_int(char a, char b)
{
	int		i;

	if (a > '9')
		i = (a - '0') * 16;
	else
		i = (a - 'A' + 10) * 16;
	if (b > '9')
		b += a - '0';
	else
		b += b - 'A' + 10;
	return (i);
}

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