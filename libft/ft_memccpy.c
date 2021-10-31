/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:25:33 by cclock            #+#    #+#             */
/*   Updated: 2020/11/10 01:19:03 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int p, size_t n)
{
	int	i;

	i = 0;
	while (n-- != 0)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		if (*(unsigned char *)(src + i) == (unsigned char)p)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
