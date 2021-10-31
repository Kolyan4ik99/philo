/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:45:15 by cclock            #+#    #+#             */
/*   Updated: 2020/11/23 18:13:41 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	int				sizened;

	i = 0;
	sizened = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	while (i < len && haystack[i] != 0)
	{
		if (*needle == haystack[i] && (i + sizened) <= len)
			if (ft_strncmp(&haystack[i], needle, sizened) == 0)
				return ((char *)&haystack[i]);
		++i;
	}
	return (NULL);
}
