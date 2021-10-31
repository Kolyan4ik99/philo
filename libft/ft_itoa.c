/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 05:57:23 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 22:30:25 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(int n)
{
	int			digit;

	digit = 0;
	if (n < 0 || n == 0)
		digit++;
	while (n != 0)
	{
		digit++;
		n /= 10;
	}
	return (digit + 1);
}

static	char	*zapol(char *str, int size, int n)
{
	int			start;
	int			i;
	long int	num;

	i = 0;
	str[size--] = '\0';
	start = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
		start = 1;
	}
	while (size >= start)
	{
		str[size] = (num % 10) + '0';
		size--;
		num /= 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int			size;
	char		*str;

	size = count(n);
	str = (char *)malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	str = zapol(str, size - 1, n);
	if (!str)
		return (NULL);
	return (str);
}
