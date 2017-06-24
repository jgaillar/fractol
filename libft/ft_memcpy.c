/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:44:17 by jgaillar          #+#    #+#             */
/*   Updated: 2017/01/05 13:44:19 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_byte	*a;
	t_byte	*b;
	size_t	i;

	i = 0;
	a = (t_byte *)src;
	b = (t_byte *)dst;
	if (n == 0)
		return (dst);
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dst);
}
