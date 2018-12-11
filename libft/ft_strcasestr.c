/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcasestr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:24:26 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:24:28 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(char const *haystack, char const *needle)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (ft_tolower(str[i + j]) == ft_tolower(needle[j]))
		{
			if (needle[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
