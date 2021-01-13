/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:40:38 by thgermai          #+#    #+#             */
/*   Updated: 2021/01/13 04:18:21 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char *str;

	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin_f12(str, ft_itoa(-n));
	}
	else if (n >= 10)
	{
		free(str);
		str = ft_strjoin_f12(ft_itoa(n / 10), ft_itoa(n % 10));
	}
	else if (n < 10 && n >= 0)
	{
		str[0] = n + 48;
		str[1] = '\0';
	}
	return (str);
}
