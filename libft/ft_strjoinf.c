/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:34:52 by jgaillar          #+#    #+#             */
/*   Updated: 2017/05/03 15:34:53 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinf(char const *s1, char const *s2, int option)
{
	char		*str;
	int			i;
	int			j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		while (s1[++i])
			str[i] = s1[i];
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		if ((option == 1 || option == 3) && s1)
			ft_strdel((char **)&s1);
		if ((option == 2 || option == 3) && s2)
			ft_strdel((char **)&s2);
		return (str);
	}
	return (NULL);
}
