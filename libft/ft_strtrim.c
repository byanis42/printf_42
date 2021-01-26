/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 04:19:51 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/26 04:19:51 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_check(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t		ft_check_end(char const *s1, char const *set)
{
	size_t state;
	size_t i;
	size_t count;

	state = 1;
	count = 0;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && state)
	{
		if (ft_check(s1[i], set))
		{
			count++;
			i--;
		}
		else
			state = 0;
	}
	return (count);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		len;
	char		*str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_check(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	len = ft_strlen(s1) - ft_check_end(s1, set) - start;
	return (str = ft_substr(s1, start, len));
}
