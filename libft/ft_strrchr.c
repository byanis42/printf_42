/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:19:26 by thgermai          #+#    #+#             */
/*   Updated: 2021/01/13 04:21:12 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(const char *s, int c)
{
	int i;

	i = 1;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strrchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c && !check(s, c))
			return ((char *)s);
		s++;
	}
	if (!c && !*s)
		return ((char *)s);
	return (NULL);
}
