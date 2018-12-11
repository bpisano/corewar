/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base_arg.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 16:20:23 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 12:42:57 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_arg(long long n, int base, t_arg *arg)
{
	char	*nbr;
	char	*s_base;
	char	*sub;
	char	*itoa;

	s_base = arg->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (n < -9223372036854775807)
		return (ft_strdup("9223372036854775808"));
	if (n < 0)
		nbr = ft_itoa_base_arg(-n, base, arg);
	else if (n < base)
		nbr = ft_strsub(s_base, n % base, 1);
	else
	{
		sub = ft_strsub(s_base, n % base, 1);
		itoa = ft_itoa_base_arg(n / base, base, arg);
		nbr = ft_strjoin(itoa, sub);
		ft_strdel(&sub);
		ft_strdel(&itoa);
	}
	return (nbr);
}

char	*ft_uitoa_base_arg(unsigned long long n, unsigned int base, t_arg *arg)
{
	char	*nbr;
	char	*s_base;
	char	*sub;
	char	*itoa;

	s_base = arg->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (n < base)
		nbr = ft_strsub(s_base, n % base, 1);
	else
	{
		sub = ft_strsub(s_base, n % base, 1);
		itoa = ft_uitoa_base_arg(n / base, base, arg);
		nbr = ft_strjoin(itoa, sub);
		ft_strdel(&sub);
		ft_strdel(&itoa);
	}
	return (nbr);
}
