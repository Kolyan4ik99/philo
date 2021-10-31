/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:35:47 by cclock            #+#    #+#             */
/*   Updated: 2020/11/10 01:31:59 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *node;

	node = *lst;
	if (!node)
	{
		*lst = new;
	}
	else
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = new;
	}
}
