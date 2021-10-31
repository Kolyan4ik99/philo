/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:45:26 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 15:26:39 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	const unsigned char	*src1;

	if (!dst && !src)
		return (NULL);
	dst1 = dst;
	src1 = src;
	if (dst > src)
	{
		dst1 += len;
		src1 += len;
		while (len-- > 0)
		{
			*--dst1 = *--src1;
		}
		return (dst1);
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
