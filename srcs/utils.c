/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:26:38 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/21 05:00:01 by yanboudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_ret(int ret, int nb_arg, ...)
{
	va_list		args;
	void		*tmp;
	int			i;

	i = 0;
	va_start(args, nb_arg);
	while (i < nb_arg)
	{
		tmp = va_arg(args, void *);
		ft_memdel(&tmp);
		i++;
	}
	va_end(args);
	return (ret);
}

int		ft_get_index(const char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '%')
			return (i);
		str++;
		i++;
	}
	return (i);
}

int		ft_define_type(char c)
{
	int		i;
	char	*value;

	i = 0;
	value = ft_strdup(CONV_FORMAT);
	while (value[i] && value[i] != c)
		i++;
	if (value[i])
		return (ft_exit(i, 1, value));
	return (ft_exit(-1, 1, value));
}

void	ft_printchar_printstr(char c, int i, char *str, int j)
{
	ft_putchar_fd(c, i);
	ft_putstr_fd(str, j);
}

void	ft_printstr_printchar(char c, int i, char *str, int j)
{
	ft_putstr_fd(str, i);
	ft_putchar_fd(c, j);
}
