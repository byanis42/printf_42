/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:15:23 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/12 22:06:56 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*ft_width_right(t_struct *settings, char *str)
{
	char		*tmp;
	
	if ((int)ft_strlen(str) > settings->width)
		return (str);
	tmp = malloc(sizeof(char) * (settings->width));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, settings->fill, settings->width - ft_strlen(str));
	tmp[settings->width - ft_strlen(str)] = '\0';
	return(ft_strjoin_f12(tmp, str));
}

char		*ft_width_left(t_struct *settings, char *str)
{
	char		*tmp;
	
	if ((int)ft_strlen(str) > settings->width)
		return (str);
	tmp = malloc(sizeof(char) * (settings->width));
	if (!tmp)
		return (NULL);
	ft_memset(tmp, settings->fill, settings->width - ft_strlen(str));
	tmp[settings->width - ft_strlen(str)] = '\0';
	return(ft_strjoin_f12(str, tmp));
}