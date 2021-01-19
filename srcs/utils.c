/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:26:38 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/19 03:21:57 by yanboudr         ###   ########.fr       */
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
	while(i < nb_arg)
	{
		tmp = va_arg(args, void *);
		ft_memdel(&tmp);
		i++;
	}
	va_end(args);
	return (ret);
}

int			ft_get_index(const char *str)
{
	int		i;

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

int			ft_define_type(char c)
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