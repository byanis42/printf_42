/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:15:35 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/13 03:34:33 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_char_pf(va_list args, t_struct *settings)
{
	char	c;
	char	*tmp;

	c = va_arg(args, int);
	tmp = ft_calloc(1, 1);
	if (!tmp)
		return (ft_ret(-1, 1, settings));
	if (settings->width)
	{
		settings->width--;
		if (settings->justif == LEFT)
		{
			tmp = ft_width_left(settings, tmp);
			ft_putchar_fd(c, 1);
			ft_putstr_fd(tmp, 1);
		}
		else
		{
			tmp = ft_width_right(settings, tmp);
			ft_putstr_fd(tmp, 1);
			ft_putchar_fd(c, 1);
		}
	}
	else 
		ft_putchar_fd(c, 1);
	return (ft_ret(settings->width + 1, 2, tmp, settings));
}

int			ft_str_pf(va_list args, t_struct *settings)
{
	char	*str;
	char	*tmp;

	str = va_arg(args, char *);
	if (!str)
		str = ft_strdup("(null)");
	else 
		str = ft_strdup(str);
	if (settings->precision != -1 && settings->precision < (int)ft_strlen(str))
		tmp = ft_substr(str, 0, settings->precision);
	else if (!settings->precision)
		tmp = ft_strdup("");
	else
		tmp = ft_strdup(str);
	if (settings->width)
	{
		if (settings->justif == LEFT)
			tmp = ft_width_left(settings, tmp);
		else
			tmp = ft_width_right(settings, tmp);
	}
	ft_putstr_fd(tmp, 1);
	return (ft_ret(ft_strlen(tmp), 3, str, tmp, settings));
}