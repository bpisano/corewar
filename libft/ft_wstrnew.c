/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrnew.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 17:49:40 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 17:53:57 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*str;

	if (!(str = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
