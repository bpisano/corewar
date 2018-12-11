/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   types.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:53:34 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 15:00:49 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "ft_printf.h"

int		num_type(t_arg *arg);
int		int_type(t_arg *arg);
int		uint_type(t_arg *arg);
int		hex_type(t_arg *arg);
int		oct_type(t_arg *arg);
int		alpha_type(t_arg *arg);
int		char_type(t_arg *arg);
int		string_type(t_arg *arg);
int		point_type(t_arg *arg);
int		percent_type(t_arg *arg);

#endif
