/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrset.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:01:07 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:03:06 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrset(wchar_t c, size_t size)
{
	wchar_t	*str;

	if (!(str = ft_wstrnew(size)))
		return (NULL);
	ft_memset(str, c, size);
	return (str);
}
