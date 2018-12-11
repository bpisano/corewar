/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrsub.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:21:30 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:27:05 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t const *s, unsigned int start, size_t size)
{
	unsigned int	i;
	wchar_t			*str;
	wchar_t			*cpy;

	if (!s)
		return (NULL);
	if (!(cpy = ft_wstrnew(size)))
		return (NULL);
	i = 0;
	str = (wchar_t *)s;
	while (i < start)
	{
		str++;
		i++;
	}
	ft_wstrncpy(cpy, str, size);
	return (cpy);
}
