/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 01:42:46 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 22:53:17 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	int				i;
	unsigned int	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	start = (start > size) ? size : start;
	if ((len - start) > size && size < len)
		len = size - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (len-- != 0 && s[start] != 0)
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}
