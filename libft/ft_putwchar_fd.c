/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wputchar_fd.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 14:55:46 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 12:11:24 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7F)
	{
		ft_putchar_fd(c, fd);
	}
	else if (c <= 0x7FF)
	{
		ft_putchar_fd((c >> 6) + 0xC0, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar_fd((c >> 12) + 0xE0, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar_fd((c >> 18) + 0xF0, fd);
		ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
}
