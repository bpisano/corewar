/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:06:51 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 14:11:59 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		signed_number(char **nbr, int n, int base)
{
	char	*itoa;

	itoa = ft_itoa_base(-n, base);
	*nbr = ft_strjoin("-", itoa);
	ft_strdel(&itoa);
}

char			*ft_itoa_base(int n, int base)
{
	char	*nbr;
	char	*s_base;
	char	*sub;
	char	*itoa;

	s_base = "0123456789ABCDEF";
	if (n == -2147483648)
		nbr = ft_strdup("-2147483648");
	else if (n < 0 && base != 10)
		nbr = ft_itoa_base(-n, base);
	else if (n < 0)
		signed_number(&nbr, n, base);
	else if (n < base)
		nbr = ft_strsub(s_base, n % base, 1);
	else
	{
		sub = ft_strsub(s_base, n % base, 1);
		itoa = ft_itoa_base(n / base, base);
		nbr = ft_strjoin(itoa, sub);
		ft_strdel(&sub);
		ft_strdel(&itoa);
	}
	return (nbr);
}
