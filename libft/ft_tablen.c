/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tablen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 19:06:25 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 19:06:34 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t      ft_tablen(char **tab)
{
	int     i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}
