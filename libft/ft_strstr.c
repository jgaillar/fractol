/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:54:15 by jgaillar          #+#    #+#             */
/*   Updated: 2017/01/05 13:54:17 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(big) == 0 && ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j] && little[j] != '\0')
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + (i - j));
		i = i - j;
		i++;
	}
	return (NULL);
}
