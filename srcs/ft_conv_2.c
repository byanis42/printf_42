/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:45:30 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/19 03:14:42 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_unsigned_pf(va_list args, t_struct *settings)
{
	unsigned int	i;
	char			*nb;
	
	i = va_arg(args, unsigned int);
	nb = ft_itoa_unsigned(i);
	if (!i && !settings->precision)
		nb = ft_strdup("");
	else if (!i)
		nb = ft_itoa(0);
	if (settings->precision != -1)
	{
		nb = ft_precision(nb, settings);
		settings->fill = ' ';
	}
	nb = ft_width_nb(settings, nb);
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, settings));
}

int				ft_hexadecimal_pf(va_list args, t_struct *settings)
{
	int		i;
	char	*nb;

	if ((i = va_arg(args, int)))
		nb = ft_itoa_base(i, HEXA);
	else if (!i && !settings->precision)
		nb = ft_strdup("");
	else
		nb = ft_itoa(0);
	if (settings->precision != -1)
	{
		nb = ft_precision(nb, settings);
		settings->fill = ' ';
	}
	if (settings->width)
	{
		if (settings->justif == LEFT)
			nb = ft_width_left(settings, nb);
		else
			nb = ft_width_right(settings, nb);
	}
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, settings));
}

int				ft_hexadecimal_upper_pf(va_list args, t_struct *settings)
{
	int		i;
	char	*nb;

	if ((i = va_arg(args, int)))
		nb = ft_str_toupper(ft_itoa_base(i, HEXA));
	else if (!i && !settings->precision)
		nb = ft_strdup("");
	else
		nb = ft_itoa(0);
	if (settings->precision != -1)
	{
		nb = ft_precision(nb, settings);
		settings->fill = ' ';
	}
	if (settings->width)
	{
		if (settings->justif == LEFT)
			nb = ft_width_left(settings, nb);
		else
			nb = ft_width_right(settings, nb);
	}
	ft_putstr_fd(nb, 1);
	return (ft_ret(ft_strlen(nb), 2, nb, settings));
}

int				ft_percent_pf(va_list args, t_struct *settings)
{
	char *tmp;

	(void)args;
	if (!(tmp = ft_strdup("%")))
		return (ft_ret(-1, 1, settings));
	if (settings->width)
	{
		if (settings->justif == LEFT)
			tmp = ft_width_left(settings, tmp);
		else
			tmp = ft_width_right(settings, tmp);
	}
	ft_putstr_fd(tmp, 1);
	return (ft_ret(ft_strlen(tmp), 2, tmp, settings));
}