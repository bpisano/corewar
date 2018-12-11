/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 18:02:39 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 17:58:46 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strset(char c, size_t size)
{
	char	*str;

	if (!(str = ft_strnew(size)))
		return (NULL);
	ft_memset(str, c, size);
	return (str);
}
