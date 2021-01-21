/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:15:23 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/21 01:39:58 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_width_right(t_struct *settings, char *str)
{
	char		*tmp;

	if ((int)ft_strlen(str) > settings->width)
		return (str);
	tmp = malloc(sizeof(char) * (settings->width - ft_strlen(str) + 1));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, settings->fill, settings->width - ft_strlen(str));
	tmp[settings->width - ft_strlen(str)] = '\0';
	return (ft_strjoin_f12(tmp, str));
}

char		*ft_width_left(t_struct *settings, char *str)
{
	char		*tmp;

	if ((int)ft_strlen(str) > settings->width)
		return (str);
	tmp = malloc(sizeof(char) * (settings->width - ft_strlen(str) + 1));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, settings->fill, settings->width - ft_strlen(str));
	tmp[settings->width - ft_strlen(str)] = '\0';
	return (ft_strjoin_f12(str, tmp));
}

char		*ft_width_nb(t_struct *settings, char *str)
{
	char	*tmp;

	if (!settings->width)
		return (str);
	if (settings->width)
	{
		if (str[0] == '-' && settings->fill == '0')
		{
			tmp = ft_strdup(str + 1);
			free(str);
			settings->width--;
			if (settings->justif == LEFT)
				str = ft_strjoin_f2("-", ft_width_left(settings, tmp));
			else
				str = ft_strjoin_f2("-", ft_width_right(settings, tmp));
			return (str);
		}
		tmp = ft_strdup(str);
		free(str);
		if (settings->justif == LEFT)
			str = ft_width_left(settings, tmp);
		else
			str = ft_width_right(settings, tmp);
	}
	return (str);
}
