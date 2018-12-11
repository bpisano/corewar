/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:25:00 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 11:37:55 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)s;
	while (str[++i])
	{
		if (str[i] == (char)c)
			return (str + i);
	}
	if (str[i] == (char)c)
		return (str + i);
	return (NULL);
}
