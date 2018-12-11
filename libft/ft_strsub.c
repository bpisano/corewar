/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:38:45 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 15:27:05 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t size)
{
	char			*str;
	char			*cpy;

	if (!s)
		return (NULL);
	if (!(cpy = ft_strnew(size)))
		return (NULL);
	str = (char *)s;
	ft_strncpy(cpy, str + start, size);
	return (cpy);
}
