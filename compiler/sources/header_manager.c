/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 17:14:50 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 17:15:15 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "compiler.h"

t_head	*new_head(void)
{
	t_head	*new;

	if (!(new = (t_head *)malloc(sizeof(t_head *))))
		return (NULL);
	new->magic = COREWAR_EXEC_MAGIC;
	return (new);
}

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

void	set_head_to_bin(int **bin, t_head head)
{
	int		i;

	add_num_to_bin(bin, 1, COREWAR_EXEC_MAGIC);
	i = -1;
	while (++i < PROG_NAME_LENGTH)
		add_int_to_bin(bin, head.prog_name[i]);
	i = -1;
	while (++i < COMMENT_LENGTH)
		add_int_to_bin(bin, head.comment[i]);
}
