#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "-0.*"
# define CONV_FORMAT "cspdiuxX%"
# define LEFT 1
# define RIGHT 0

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h> // Temp a supprimer

typedef	struct	s_struct
{
	int		width;
	int		convert;
	int		justif;
	int		precision;
	char	fill;

}				t_struct;

int				ft_printf(const char *str, ...);

int				print_till_next_arg(char *str);
t_struct		*ft_parse(const char *str, va_list args);

int			ft_str_pf(va_list args, t_struct *settings);
int			ft_char_pf(va_list args, t_struct *settings);

char		*ft_width_right(t_struct *settings, char *str);
char		*ft_width_left(t_struct *settings, char *str);


int		ft_ret(int ret, int nb_arg, ...);


#endif