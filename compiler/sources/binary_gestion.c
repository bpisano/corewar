/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary_gestion.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:55:13 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/24 17:51:15 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "compiler.h"

char	*new_bin()
{
	char	*new;
	
	if (!(new = (char *)malloc(sizeof(char))))
		return (NULL);
	new[0] = 0;
	return (new);
}

char	add_to_bin(char **bin, char b)
{
	int		oldSize;
	
	oldSize = (*bin)[0];
	if (!(*bin = (char *)realloc(*bin, sizeof(b) * (oldSize + 1))))
		return (0);
	(*bin)[0] = oldSize + 1;
	(*bin)[oldSize + 1] = b;
	return (1);
}

char	add_str_to_bin(char **bin, char *str)
{
	int		i;
	
	i = -1;
	while (str[++i])
		if (!add_to_bin(bin, str[i]))
			return (0);
	return (1);
}

void 	free_binary(char **binary)
{
	free(*binary);
}
