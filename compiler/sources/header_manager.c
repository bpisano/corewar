/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 12:19:00 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 18:50:17 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "compiler.h"

void	set_head_name(t_head *head, char *name)
{
	int		i;

	ft_bzero(head->prog_name, PROG_NAME_LENGTH);
	i = -1;
	while (name[++i])
		head->prog_name[i] = name[i];
}

void	set_head_comment(t_head *head, char *com)
{
	int		i;

	ft_bzero(head->comment, COMMENT_LENGTH);
	i = -1;
	while (com[++i])
		head->comment[i] = com[i];
}
