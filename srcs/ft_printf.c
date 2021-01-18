/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:38:13 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/17 00:55:49 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

const char		*ft_refresh_str(const char *str)
{
	int				next_arg;

	next_arg = ft_get_index(str);
	if (str[next_arg] == '%')
	{
		next_arg++;
		while (str[next_arg] && ft_define_type(str[next_arg]) == -1)
			next_arg++;
		next_arg++;
	}
	return (str + next_arg);
}

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

/*static void		print_setting(t_struct *settings) // Temp
{
	printf("width : %d\n", settings->width);
	printf("convert : %d\n", settings->convert);
	printf("justif : %d\n", settings->justif);
	printf("precision : %d\n", settings->precision);
	printf("fill : '%c'\n", settings->fill);
}*/

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
	function_ptr[8] = &ft_percent_pf;
	return ((*function_ptr[settings->convert])(args, settings));
}	

int				ft_print_str(const char *str, int i)
{
	char		*output;

	output = ft_substr(str, 0, ft_get_index(str));
	if (!output)
		return (ft_ret(-1, 0));
	ft_putstr_fd(output, 1);
	return (ft_ret(i + ft_strlen(output), 1, output));
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	//t_struct 	*settings;
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	va_start(args, str);
	while (*str)
	{
		if ((i = ft_print_str(str, i)) == -1)
			break ;
		if (str[ft_get_index(str)] == '%')
		{
			if ((ret = ft_func_array(args, ft_parse(str +
				ft_get_index(str), args))) == -1)
			{
				i = -1;
				break ;
			}
			i = i + ret;
		}
		str = ft_refresh_str(str);
	}
	
	/*
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
	*/


	va_end(args);
	return (ft_exit(i, 0));
}