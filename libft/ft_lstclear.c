/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:32:31 by cclock            #+#    #+#             */
/*   Updated: 2020/11/18 19:27:49 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *node;

	if (!(*lst))
		return ;
	if (del)
	{
		while (*lst != NULL)
		{
			node = (*lst)->next;
			ft_lstdelone(*lst, *del);
			free(*lst);
			*lst = node;
		}
		*lst = NULL;
	}
}
