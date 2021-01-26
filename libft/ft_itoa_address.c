/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 04:10:55 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/26 04:10:55 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_address(unsigned long long int n)
{
	char		*str;
	char		*base;

	base = ft_strdup("0123456789abcdef");
	str = (char *)ft_calloc(sizeof(char), 2);
	if (!str)
		return (NULL);
	else if (n >= 16)
	{
		free(str);
		str = ft_strjoin_f12(ft_itoa_address(n / 16),
			ft_itoa_address(n % 16));
	}
	else if (n < 16 && n >= 0)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	free(base);
	return (str);
}
