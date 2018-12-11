/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:10:50 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 11:38:49 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->content = content ? ft_memalloc(content_size) : NULL;
	new->content_size = content ? content_size : 0;
	new->next = NULL;
	if (content)
		ft_memcpy(new->content, content, content_size);
	return (new);
}
