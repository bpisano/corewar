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

int		*new_bin()
{
	int		*new;
	
	if (!(new = (int *)malloc(sizeof(int))))
		return (NULL);
	new[0] = 0;
	return (new);
}

int		add_to_bin(int **bin, int b)
{
	int		oldSize;
	
	oldSize = (*bin)[0];
	if (!(*bin = (int *)realloc(*bin, sizeof(int) * (oldSize + 1))))
		return (0);
	(*bin)[0] = oldSize + 1;
	(*bin)[oldSize + 1] = b;
	return (1);
}

void 	free_binary(int **binary)
{
	free(*binary);
}
