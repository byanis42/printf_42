/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:33:39 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/19 23:52:49 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		ft_init_settings(t_struct *settings)
{
	settings->fill = ' ';
	settings->width = 0;
	settings->precision = -1;
	settings->convert = -1; // "cspdiuxX%"
	settings->justif = RIGHT;
}

static	int		ft_get_conv(char c)
{
	int		i;
	char	*charset;

	i = -1;
	charset = ft_strdup(CONV_FORMAT);
	while(charset[++i])
	{	
		if (charset[i] == c)
		{
			free(charset);
			return(i);
		}
	}
	free(charset);
	return (-1);
}

static void		ft_start_parsing(const char *str, t_struct *settings, va_list args)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == '-')
			settings->justif = LEFT;
		else if (str[i] == '.')
		{
			++i;
			if (ft_get_conv(str[i]) != -1)
			{
				settings->precision = 0;
				--i;
			}
			else if (str[i] == '*') //&& !settings->width) // peut-etre enlever !set..width
				settings->precision = va_arg(args, int);
			else 
				settings->precision = ft_atoi(str + i);
			while (ft_isdigit(str[i] || str[i]) == '*')
				i++;
		}
		else if (str[i] == '*' && !settings->width)
				settings->width = va_arg(args, int);
		else if (str[i] == '0')
			settings->fill = '0';
		else if (ft_isdigit(str[i]))
		{
			settings->width = ft_atoi(str + i);
			while (str[i + 1] && ft_isdigit(str[i + 1]))
				i++;
		}
		else
		{
			settings->convert = ft_get_conv(str[i]);
			break ;
		}
	}
}
	
 static void			verify_settings(t_struct *settings)
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
		return (NULL); // handle error;

	ft_init_settings(settings);
	ft_start_parsing(str ,settings, args);
	verify_settings(settings);
	// print_setting(settings);
	
	return (settings);
}