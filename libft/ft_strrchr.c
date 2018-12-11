/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:37:36 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:37:40 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	*ret;

	i = 0;
	str = (char *)s;
	ret = NULL;
	while (str[i])
	{
		if (str[i] == (char)c)
			ret = &str[i];
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (ret);
}
