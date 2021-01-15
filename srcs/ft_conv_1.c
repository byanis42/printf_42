/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:15:35 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/15 05:22:40 by yanboudr         ###   ########.fr       */
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

int				ft_address_pf(va_list args, t_struct *settings)
{
	void	*ptr;
	char	*result;

	ptr = va_arg(args, void *);
	if (!settings->precision)
		result = ft_strdup("");
	else if (!ptr)
		result = ft_strdup("0");
	else
		result = ft_itoa_address((unsigned long long int)ptr);
	if (settings->precision != -1 && settings->precision)
	{
		result = ft_precision(result, settings);
		settings->fill = ' ';
	}
	result = ft_strjoin_f2("0x", result);
	result = ft_width_nb(settings, result);
	ft_putstr_fd(result, 1);
	return (ft_ret(ft_strlen(result), 2, result, settings));
} 

int			ft_decimal_pf(va_list args, t_struct *settings)
{
	int		i;
	char	*nb;
	
	i = va_arg(args, int);
	nb = ft_itoa(i);
	 if (!i && !settings->precision)
		nb = ft_strdup("");
	else if (!i)
		nb = ft_itoa(0);
	if (settings->precision != -1)
	{
		nb = ft_precision_nb(nb, settings);
		settings->fill = ' ';              // possiblement a remettre -- regarder comportement avec .014
	}
	nb = ft_width_nb(settings, nb);
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, settings));
}

int				ft_integer_pf(va_list args, t_struct *settings)
{
	int		i;
	char	*nb;

	if ((i = va_arg(args, int)))
		nb = ft_itoa(i);
	else if (!i && !settings->precision)
		nb = ft_strdup("");
	else
		nb = ft_itoa(0);
	if (settings->precision != -1)
	{
		nb = ft_precision_nb(nb, settings);
		settings->fill = ' ';
	}
	nb = ft_width_nb(settings, nb);
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, settings));
}