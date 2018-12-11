/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtowchr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 20:19:07 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 13:05:38 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

wchar_t	*ft_strtowchr(const char *str)
{
	int		i;
	wchar_t	*new;

	if (!(new = ft_wstrnew(ft_strlen(str))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
