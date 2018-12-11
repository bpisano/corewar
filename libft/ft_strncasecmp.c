/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncasecmp.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:33:49 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:33:51 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncasecmp(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] &&
			(unsigned char)ft_tolower(s1[i]) ==
			(unsigned char)ft_tolower(s2[i]) &&
			i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
