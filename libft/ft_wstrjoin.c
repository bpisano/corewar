/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:09:19 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:17:37 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2)
{
	wchar_t	*join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = ft_memalloc(ft_wstrlen(s1) + ft_wstrlen(s2) + 1)))
		return (NULL);
	ft_wstrcpy(join, s1);
	ft_wstrcat(join, s2);
	return (join);
}
