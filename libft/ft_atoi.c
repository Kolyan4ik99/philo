/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:00:37 by cclock            #+#    #+#             */
/*   Updated: 2020/11/09 20:49:30 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int		reverse(const char *str)
{
	int			i;
	long int	sum;

	i = 0;
	sum = 0;
	while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
	{
		sum = sum + (str[i] - '0');
		sum *= 10;
		i++;
	}
	sum /= 10;
	return (sum);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			minus;
	int			cout;

	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		cout = reverse(&str[i]);
		return (cout * minus);
	}
	return (0);
}
