/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:53:36 by jgaillar          #+#    #+#             */
/*   Updated: 2017/01/05 13:53:38 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char*)big);
	i = 0;
	j = 0;
	while (big[j] && j < len)
	{
		if (big[j] == little[i])
			i++;
		else
		{
			j = j - i;
			i = 0;
		}
		if (little[i] == '\0')
			return ((char*)&(big[j - i + 1]));
		j++;
	}
	return (NULL);
}
