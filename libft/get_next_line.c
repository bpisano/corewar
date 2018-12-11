/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 11:52:58 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 14:43:23 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_readline(const int fd, char *buff, int *ret)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;

	if ((*ret = read(fd, tmp, BUFF_SIZE)) < 0)
		return (0);
	tmp[*ret] = 0;
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, tmp)))
		return (0);
	free(tmp2);
	return (buff);
}

int			ft_cpy_end(char **line, char **buff)
{
	if (!(*line = ft_strdup(*buff)))
		return (-1);
	ft_bzero(*buff, ft_strlen(*buff));
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*buff = NULL;
	int				ret;
	char			*str;

	ret = 1;
	if (!line || fd < 0 || BUFF_SIZE < 1 || (!buff && !(buff = ft_memalloc(1))))
		return (-1);
	while (ret > 0)
	{
		if ((str = ft_strchr(buff, '\n')))
		{
			*str = 0;
			if (!(*line = ft_strdup(buff)))
				return (-1);
			ft_strcpy(buff, str + 1);
			return (1);
		}
		if (!(buff = ft_readline(fd, buff, &ret)))
			return (-1);
	}
	free(str);
	if (!ret && ft_strlen(buff))
		ret = ft_cpy_end(line, &buff);
	(!(*buff)) ? ft_memdel((void *)&buff) : 0;
	return (ret);
}
