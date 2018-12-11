/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcasecmp.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:24:12 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:24:15 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] &&
			(unsigned char)ft_tolower(s1[i]) ==
			(unsigned char)ft_tolower(s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
