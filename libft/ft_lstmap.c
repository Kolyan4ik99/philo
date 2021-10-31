/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:00:21 by cclock            #+#    #+#             */
/*   Updated: 2020/11/10 02:31:32 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*listik;

	listik = NULL;
	while (lst != NULL)
	{
		map = ft_lstnew((f)(lst->content));
		if (map == NULL)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&listik, map);
		lst = lst->next;
	}
	return (listik);
}
