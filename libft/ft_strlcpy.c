/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:59:52 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 15:33:34 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	int				flag;

	flag = 0;
	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < (dstsize - 1))
	{
		dst[i] = src[i];
		if (dst[i] == '\0' && src)
			return (ft_strlen(src));
		i++;
		flag = 1;
	}
	if (flag == 1)
		dst[i] = '\0';
	return (ft_strlen(src));
}
