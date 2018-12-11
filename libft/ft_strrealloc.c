/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrealloc.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 21:00:54 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 16:47:21 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *ptr, size_t size)
{
	char	*new;

	if (!(new = ft_strnew(size)))
		return (NULL);
	ft_strcpy(new, ptr);
	ft_memdel((void **)&ptr);
	return (new);
}
