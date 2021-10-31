/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 06:17:55 by cclock            #+#    #+#             */
/*   Updated: 2020/11/08 21:53:21 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s[i] != 0)
	{
		str[i] = (f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
