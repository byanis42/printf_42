/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:33:39 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/21 05:09:25 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		ft_init_settings(t_struct *settings)
{
	settings->fill = ' ';
	settings->width = 0;
	settings->precision = -1;
	settings->convert = -1;
	settings->justif = RIGHT;
}

static	int		ft_get_conv(char c)
{
	int		i;
	char	*charset;

	i = -1;
	charset = ft_strdup(CONV_FORMAT);
	while (charset[++i])
	{
		if (charset[i] == c)
		{
			free(charset);
			return (i);
		}
	}
	free(charset);
	return (-1);
}

static void		ft_start_parsing(const char *str,
	t_struct *settings, va_list args)
{
	int		i;

	i = 0;
	while (ft_find_in(FLAGS, str[i]) || ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			settings->justif = LEFT;
		else if (str[i] == '.')
		{
			if (*(str + i + 1) == '*')
				settings->precision = va_arg(args, int);
			else
				settings->precision = ft_atoi(str + i + 1);
			while (ft_isdigit(*(str + i + 1)) || *(str + i + 1) == '*')
				i++;
		}
		else if (str[i] == '0' && !settings->width)
			settings->fill = '0';
		else if (str[i] == '*' && !settings->width)
			settings->width = va_arg(args, int);
		else if (!settings->width)
			settings->width = ft_atoi(str + i);
		i++;
	}
	settings->convert = ft_get_conv(str[i]);
}

static void		ft_verify_settings(t_struct *settings)
{
	if (settings->width < 0)
	{
		settings->width *= -1;
		settings->justif = LEFT;
	}
	if (settings->precision < 0)
		settings->precision = -1;
	if (settings->fill == '0' && settings->justif == LEFT)
		settings->fill = ' ';
}

t_struct		*ft_parse(const char *str, va_list args)
{
	t_struct	*settings;

	settings = malloc(sizeof(t_struct) * 1);
	if (!settings)
		return (NULL);
	ft_init_settings(settings);
	if (!settings)
		return (NULL);
	str++;
	ft_start_parsing(str, settings, args);
	ft_verify_settings(settings);
	return (settings);
}
