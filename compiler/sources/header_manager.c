/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 11:14:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 17:44:31 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

void	set_head_name(t_head *head, char *name)
{
	int		i;

	ft_bzero(head->prog_name, PROG_NAME_LENGTH);
	i = -1;
	while (name[++i] && i < PROG_NAME_LENGTH)
		head->prog_name[i] = name[i];
}

void	set_head_comment(t_head *head, char *com)
{
	int		i;

	ft_bzero(head->comment, COMMENT_LENGTH);
	i = -1;
	while (com[++i] && i < COMMENT_LENGTH)
		head->comment[i] = com[i];
}
