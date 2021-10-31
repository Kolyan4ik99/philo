/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 03:55:43 by cclock            #+#    #+#             */
/*   Updated: 2020/11/19 23:47:20 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(char const *s, char c)
{
	int			cs;
	int			start;
	int			end;

	start = 0;
	cs = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == c && s[start] != 0)
		start++;
	while (s[end] == c)
		end--;
	while (start <= end)
	{
		if (s[start] == c && s[start + 1] != c)
			cs++;
		start++;
	}
	return (cs + 1);
}

static char		**vydel(char **str, char const *s, char c, int gc)
{
	int			i;
	int			j;
	int			cs;

	cs = 0;
	i = 0;
	j = 0;
	while (gc-- != 0)
	{
		while (s[i] == c && s[i] != 0)
			++i;
		while (s[i] != c && s[i++] != 0)
			++j;
		str[cs] = (char *)malloc(sizeof(char) * (j + 1));
		if (((j = 0) == 0) && !str[cs])
		{
			while (str[cs] && cs >= 0)
			{
				while (cs >= 0)
					free(str[cs--]);
			}
		}
		++cs;
	}
	return (str);
}

static char		**zapol(char **str, char const *s, char c, int gc)
{
	int			i;
	int			j;
	int			cs;

	cs = 0;
	i = 0;
	j = 0;
	while (gc-- != 0)
	{
		while (s[i] == c && s[i] != 0)
			i++;
		while (s[i] != c && s[i] != 0)
			str[cs][j++] = s[i++];
		str[cs][j] = '\0';
		++cs;
		j = 0;
	}
	return (str);
}

static char		**check_null(char const *s, char c)
{
	char		**str;
	int			i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
			return (NULL);
		i++;
	}
	str = (char **)malloc(sizeof(char *) * 1);
	str[0] = NULL;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char		**str;
	int			gc;

	if (!s)
		return (NULL);
	if ((str = check_null(s, c)) != NULL)
	{
		return (str);
	}
	gc = count(s, c);
	if ((str = (char **)malloc(sizeof(char *) * (gc + 1))) == NULL)
		return (NULL);
	str[gc] = NULL;
	str = vydel(str, s, c, gc);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (zapol(str, s, c, gc));
}
