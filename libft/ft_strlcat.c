/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:34:15 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 18:19:04 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print(char *dst, const char *src, size_t size)
{
	while (*src != 0)
	{
		if (size != 0)
		{
			size--;
			*dst++ = *src;
		}
		src++;
	}
	*dst = '\0';
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*odst;
	const char	*osrc;
	size_t		size;
	size_t		n;

	if (!dst && !src)
		return (0);
	odst = dst;
	osrc = src;
	size = dstsize;
	while (size != 0 && *dst != '\0')
	{
		size--;
		dst++;
	}
	n = dst - odst;
	size = dstsize - n;
	if (size-- == 0)
		return (n + ft_strlen(src));
	print(dst, src, size);
	return (n + ft_strlen(src));
}
