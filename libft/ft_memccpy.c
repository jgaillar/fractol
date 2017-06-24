/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:45:59 by jgaillar          #+#    #+#             */
/*   Updated: 2017/01/05 13:46:02 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_byte	*s;
	t_byte	*d;
	t_byte	unc;
	size_t	i;

	i = 0;
	s = (t_byte *)src;
	d = (t_byte *)dst;
	unc = (t_byte)c;
	while (i < n)
	{
		if ((*d++ = *s++) == unc)
			return (d);
		i++;
	}
	return (NULL);
}
