/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstat.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 13:10:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:55:04 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list **lst, unsigned int index)
{
	unsigned int	i;
	t_list			*current;

	i = 0;
	current = *lst;
	while (current && i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}
