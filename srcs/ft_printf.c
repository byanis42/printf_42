/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:38:13 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/15 05:34:41 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				print_till_next_arg(char *str)
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

int				ft_func_array(va_list args, t_struct *settings)
{
	int		(*function_ptr[9])(va_list, t_struct *);
	
	if (!settings)
		return(ft_ret(-1, 0));
	if (settings->convert < 0)
		return (ft_ret(-1, 1, settings));
	function_ptr[0] = &ft_char_pf;
	function_ptr[1] = &ft_str_pf;
	function_ptr[2] = &ft_address_pf;
	function_ptr[3] = &ft_decimal_pf;
	function_ptr[4] = &ft_integer_pf;
	function_ptr[5] = &ft_unsigned_pf;
	function_ptr[6] = &ft_hexadecimal_pf;
	function_ptr[7] = &ft_hexadecimal_upper_pf;
	function_ptr[8] = &ft_precision;
	return ((*function_ptr[settings->convert])(args, settings));
}	

int				ft_printf(const char *str, ...)
{
	va_list		args;
	t_struct 	*settings;
	int			ret;

	ret = 0;
	va_start(args, str);
	
	ret = print_till_next_arg((char *)str);
	str = str + ret;
	
	settings = ft_parse(str, args);
	//print_setting(settings);
	//ft_char_pf(args, settings);
	//ft_str_pf(args, settings);
	//ft_decimal_pf(args, settings);
	//ft_address_pf(args, settings);
	ft_unsigned_pf(args, settings);
	//free(settings);
	
	va_end(args);
	return (0);
}