/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:21:34 by jgaillar          #+#    #+#             */
/*   Updated: 2017/05/04 16:37:17 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchri(char *s, char c)
{
	size_t j;

	j = -1;
	while (s[++j] != c || s[j])
		if (s[j] == c)
			return (j);
	if (c == '\0')
		return (j);
	return (0);
}

char	*readfile(int fd, t_gnl *gnl, int j)
{
	char	*rt;
	char	buf[BUFF_SIZE + 1];

	gnl->i = -1;
	rt = NULL;
	gnl->tmp = ft_strnew(0);
	while ((gnl->ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[gnl->ret] = '\0';
		gnl->tmp = ft_strjoinf(gnl->tmp, buf, 1);
		if (ft_strchr(gnl->tmp, '\n') && gnl->tmp[++j])
			break ;
	}
	if (gnl->ret == 0 && ft_strlen(gnl->tmp) == 0)
		return (NULL);
	if (ft_strlen(gnl->tmp) > 0)
	{
		rt = (j == 1 ? (char *)ft_strnew(sizeof(char) * (ft_strchri(gnl->tmp, \
			'\n'))) : (char *)ft_strnew(sizeof(char) * \
			(ft_strchri(gnl->tmp, '\0'))));
		while (gnl->tmp[++gnl->i] != '\n' && gnl->tmp[gnl->i] != '\0')
			rt[gnl->i] = gnl->tmp[gnl->i];
		rt[gnl->i] = '\0';
	}
	return (rt);
}

int		ft_overtake(char **overtake, char **line)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	if (*overtake)
	{
		tmp = ft_strsub(*overtake, 0, ft_strlen(*overtake));
		while (tmp[++i] != '\n' && tmp[i] != '\0')
			continue;
		*line = ft_strsub(tmp, 0, i);
		if (tmp[i] == '\n')
		{
			tmp = ft_strsub(*overtake, i + 1, ft_strlen(*overtake) - i);
			*overtake = ft_strsub(tmp, 0, ft_strlen(tmp));
			ft_strdel(&tmp);
			return (1);
		}
		ft_strdel(overtake);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	t_gnl		gnl;
	char		*tmp;
	static char *overtake;

	if (fd < 0 || !line || read(fd, gnl.buf, 0) < 0)
		return (-1);
	*line = NULL;
	if (!(*line))
		*line = ft_strnew(0);
	gnl.ret = 0;
	if (ft_overtake(&overtake, line) == 1)
		return (1);
	tmp = readfile(fd, &gnl, -1);
	if (tmp != NULL)
		*line = ft_strjoinf(*line, tmp, 3);
	if (gnl.tmp[gnl.i] == '\n')
	{
		overtake = ft_strsub(gnl.tmp, gnl.i + 1, \
		ft_strlen(gnl.tmp));
		ft_strdel(&gnl.tmp);
		return (1);
	}
	return (ft_strlen(*line) == 0 && \
	!gnl.ret && ft_strlen(overtake) == 0 ? 0 : 1);
}
