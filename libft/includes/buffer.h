/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   buffer.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 11:16:36 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 12:28:44 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include "ft_printf.h"

typedef struct	s_buff
{
	char		*buff;
	int			buff_size;
	char		*value;
	int			v_size;
	char		*sup;
	int			sup_size;
	int			sup_pos;
	int			arg_offset;
	int			resized_value;
}				t_buff;

t_buff			*new_buff();
void			free_buff(t_buff *buffer);

void			resize_value(t_buff **buffer, t_arg *arg);
void			set_buff_value(t_buff **buffer, t_arg *arg);
void			set_buff_sup(t_buff **buffer, t_arg *arg);
void			set_buff_size(t_buff **buffer, t_arg *arg);
void			set_buff_sup_pos(t_buff **buffer, t_arg *arg);
t_buff			*percent_buffer(char *format, va_list params);

#endif
