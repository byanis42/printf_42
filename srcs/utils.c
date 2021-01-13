/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanboudr <yanboudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:26:38 by yanboudr          #+#    #+#             */
/*   Updated: 2021/01/12 00:31:09 by yanboudr         ###   ########.fr       */
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