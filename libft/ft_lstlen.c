/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 15:44:14 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 15:46:16 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *lst)
{
	int		i;
	t_list	*iterator;

	i = 0;
	iterator = lst;
	while (iterator)
	{
		i++;
		iterator = iterator->next;
	}
	return (i);
}
