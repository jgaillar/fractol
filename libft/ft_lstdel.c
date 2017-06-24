/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:08:40 by jgaillar          #+#    #+#             */
/*   Updated: 2016/11/30 10:56:36 by jgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	tmp = NULL;
	while ((*alst))
	{
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		if ((*alst))
			free((*alst));
		(*alst) = NULL;
		(*alst) = tmp;
	}
}
