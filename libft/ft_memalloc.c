/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:44:03 by jgaillar          #+#    #+#             */
/*   Updated: 2017/01/05 13:44:05 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*newalloc;

	if (!(newalloc = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_memset(newalloc, 0, size);
	return (newalloc);
}
