/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:17:11 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 15:32:13 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	int		b;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	b = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	if (s[i] == (char)c && b == 0)
		return (&ptr[i]);
	return (NULL);
}
