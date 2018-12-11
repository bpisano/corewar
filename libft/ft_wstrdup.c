/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrdup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:19:53 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:20:34 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(const wchar_t *s1)
{
	int		i;
	int		len;
	wchar_t	*dup;

	if (!s1)
		return (ft_wstrnew(0));
	i = 0;
	len = ft_wstrlen(s1);
	if (!(dup = ft_wstrnew(len)))
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
