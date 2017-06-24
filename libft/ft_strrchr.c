/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:53:55 by jgaillar          #+#    #+#             */
/*   Updated: 2017/01/05 13:53:57 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	charc;

	charc = (char)c;
	i = ft_strlen(s);
	if (charc == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == charc)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
