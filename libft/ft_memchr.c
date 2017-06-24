/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:44:28 by jgaillar          #+#    #+#             */
/*   Updated: 2017/01/05 13:44:30 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte	*src;
	t_byte	uncharc;
	size_t	i;

	src = (t_byte *)s;
	i = 0;
	uncharc = (t_byte)c;
	while (n--)
	{
		if (src[i] == uncharc)
			return (src + i);
		i++;
	}
	return (NULL);
}
