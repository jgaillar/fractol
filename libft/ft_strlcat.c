/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:52:02 by jgaillar          #+#    #+#             */
/*   Updated: 2017/01/05 13:52:04 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	t_size;
	size_t	i;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	t_size = size_dest + size_src;
	i = 0;
	while (src[i] && size_dest < size - 1 && size != 0)
		dest[size_dest++] = src[i++];
	dest[size_dest] = '\0';
	if (size < t_size - size_src)
		return (size + size_src);
	return (t_size);
}
