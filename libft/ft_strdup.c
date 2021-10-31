/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 01:30:30 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 15:32:30 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		flag;

	i = 0;
	while (s1[i] != 0)
		i++;
	s2 = (char *)malloc((sizeof(char) * (i + 1)));
	if (!s2)
		return (NULL);
	flag = 0;
	while (flag < i)
	{
		s2[flag] = s1[flag];
		flag++;
	}
	s2[flag] = '\0';
	return (s2);
}
