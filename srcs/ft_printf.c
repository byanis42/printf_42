/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:38:13 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/13 03:39:52 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_till_next_arg(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '%')
			break ;
	write(1, str, i);
	return (i);
}

static void		print_setting(t_struct *settings) // Temp
{
	printf("width : %d\n", settings->width);
	printf("convert : %d\n", settings->convert);
	printf("justif : %d\n", settings->justif);
	printf("precision : %d\n", settings->precision);
	printf("fill : '%c'\n", settings->fill);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	t_struct 	*settings;
	int			ret;

	ret = 0;
	va_start(args, str);
	
	ret = print_till_next_arg((char *)str);
	str = str + ret;
	
	settings = ft_parse(str, args);
	print_setting(settings);
	int z = ft_char_pf(args, settings);
	
	va_end(args);
	return (0);
}