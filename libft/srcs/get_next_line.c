/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <imhaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 19:43:28 by imhaimou          #+#    #+#             */
/*   Updated: 2018/03/24 13:15:29 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_stock(char **r, char **line, char *buf)
{
	char		*tmp;

	if (ft_strlen(*r) > 0)
	{
		tmp = *r;
		*line = ft_strjoin(tmp, buf);
		free(*r);
		*r = NULL;
		return (1);
	}
	return (0);
}

static int		result(char **r, char **line)
{
	char		*tmp;

	*line = ft_strsub(*r, 0, ft_strchr(*r, '\n') - *r);
	tmp = *r;
	*r = ft_strsub(tmp, ft_strlen(*line) + 1, ft_strlen(tmp) \
		- ft_strlen(*line));
	free(tmp);
	return (*r ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char *r = NULL;
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (*line)
		*line = "";
	r = !r ? ft_strnew(1) : r;
	while (!(ft_strchr(r, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0)
			return (ft_stock(&r, line, buf));
		tmp = r;
		r = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (result(&r, line));
}
