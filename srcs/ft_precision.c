/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:13:57 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/21 01:35:44 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_precision(char *str, t_struct *settings)
{
	char	*tmp;

	if ((int)ft_strlen(str) >= settings->precision)
		return (str);
	tmp = malloc(sizeof(char) * (settings->precision - ft_strlen(str)));
	if (!str)
		return (NULL);
	ft_memset(tmp, '0', settings->precision - ft_strlen(str));
	tmp[settings->precision - ft_strlen(str)] = '\0';
	return (ft_strjoin_f12(tmp, str));
}

char		*ft_precision_nb(char *str, t_struct *settings)
{
	char	*tmp;

	tmp = NULL;
	if (settings->precision != -1)
	{
		if (str[0] == '-')
		{
			tmp = ft_strdup(str + 1);
			free(str);
			str = ft_strjoin_f2("-", ft_precision(tmp, settings));
		}
		else
			str = ft_precision(str, settings);
	}
	return (str);
}
