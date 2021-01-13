/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 10:19:24 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/03 10:52:50 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdarg.h"

int		ft_exit(int ret, int n, ...)
{
	va_list		argv;
	void		*temp;
	int			i;

	i = 0;
	va_start(argv, n);
	while (i < n)
	{
		temp = va_arg(argv, void *);
		ft_memdel(&temp);
		i++;
	}
	va_end(argv);
	return (ret);
}
