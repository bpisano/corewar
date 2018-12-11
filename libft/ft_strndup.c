/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:36:15 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:36:17 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s, size_t n)
{
	char	*dup;

	if (!(dup = ft_memalloc(n + 1)))
		return (NULL);
	ft_strncpy(dup, s, n);
	return (dup);
}
