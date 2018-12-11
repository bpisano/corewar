/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 11:19:03 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 15:14:46 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ARG_H
# define ARG_H

# include "ft_printf.h"
# include <stdlib.h>
# include <stdarg.h>

typedef union			u_value
{
	char				schar;
	wchar_t				swchar;
	short				sshort;
	int					sint;
	long				slong;
	long long			sllong;
	intmax_t			sintmax;

	unsigned char		uchar;
	unsigned short		ushort;
	unsigned int		uint;
	unsigned long		ulong;
	unsigned long long	ullong;
	uintmax_t			uintmax;

	size_t				sizet;
	char				*string;
	wchar_t				*wstring;
}						t_value;

typedef struct			s_flag
{
	char				flag;
	struct s_flag		*next;
}						t_flag;

typedef struct			s_arg
{
	t_value				*value;
	char				type;
	t_flag				*flag;
	int					f_width;
	int					prec;
	char				*modifier;
	int					offset;
}						t_arg;

/*
 ** Memory management
*/
t_arg					*new_arg(void);
void					free_arg(t_arg *arg);

/*
 ** Args
*/
t_arg					*get_arg(char *format, va_list params, int i);

/*
 ** Flags
*/
t_flag					*new_flag(char flag);
void					free_flag(t_flag *f);
void					free_flags(t_arg *arg);
int						flag(t_arg *arg, char flag);
int						add_flag(t_arg *arg, char f);

/*
 ** Values
*/
long long				arg_v(t_arg *arg);
unsigned long long		uarg_v(t_arg *arg);
void					set_arg_value(t_arg **arg, char type, int offset,
		va_list params);

#endif
