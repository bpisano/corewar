/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lst_push_back.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:07:09 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 13:07:17 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **lst, t_list *new)
{
	t_list *iterator;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	iterator = *lst;
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = new;
}
