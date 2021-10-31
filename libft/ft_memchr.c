/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:00:48 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 15:25:36 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- != 0)
	{
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((char *)--s);
	}
	return (NULL);
}
