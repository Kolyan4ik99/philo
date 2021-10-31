/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:45:27 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 15:26:20 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- != 0)
	{
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
			return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	}
	return (0);
}
